#!/usr/bin/python3.5
# @Author: Giovanni Camurati <Camurati>, Corteggiani Nassim <Corteggiani>
# @Date:   04-July-2017
# @Email:  camurati@eurecom.fr, nassim.corteggiani@maximintegrated.com
# @Filename: generator.py
# @Last modified by:   Camurati
# @Last modified time: 04-July-2017
# @License: GPLv3

# Import the interactive module, responsible for the communication with the real
# device. Set the path to the libinception cpp library that handles jtag. Use it
# in non command line mode
import sys
import time
import os
sys.path.append('../RTDebugger-driver/src/')
import interactive
from collections import OrderedDict
import random
import os_run
import getopt
import ldrstr

# read command line args
def print_usage_error():
    print("Wrong parameters, usage:")
    print("./generator.py \
           -s <seed> \
           -c <(continue in case of error) True/False> \
           [-n (no device)] \
           [-o <output folder> \
           [-N <number of tests per instruction>")
    sys.exit(0)

no_device = False
folder="test_cases"
tests_per_instruction=1

if len(sys.argv) <= 1:
    print_usage_error()
try:
    opts,args = getopt.getopt(sys.argv[1:],"hs:c:no:N:",["help",
                                                       "seed=",
                                                       "continue=",
                                                       "no-device",
                                                       "output-folder=",
                                                       "tests-per-instruction="])
except getopt.GetoptError:
    print_usage_error()
for opt,arg in opts:
    if opt in ("-h","--help"):
        print("./generator.py")
        print("options:")
        print("    s,seed=:                     integer seed for pseudo random test generation")
        print("    c,continue=:                 True->skip errors, False->stop on error")
        print("    n,no-device:                 skip execution on device")
        print("    o,output-folder=:            folder where test cases are stored")
        print("    N,tests-per-instrcutionr=:   number of tests per instruction")
        print("")
    elif opt in ("-s","--seed"):
        seed = int(arg)
    elif opt in ("-c","--continue"):
        if arg == "True":
            cont = True
        elif arg == "False":
            cont = False
        else: 
            print("Error, continue must be True or False")
            sys.exit(1)
    elif opt in ("-n","--no-device"):
            no_device = True
    elif opt in ("-o","--output-folder="):
            folder = arg 
    elif opt in ("-N","--tests-per-instruction="):
            tests_per_instruction = int(arg) 


random.seed(seed)

# create output folder
os_run.run_catch_error('mkdir -p %s'%folder,cont)

# save version
vfile = os.path.abspath(folder+"/version_generator.log")
os_run.run_catch_error("./versioning.sh %s"%(vfile),False)


# the real device, used as golden model
if(no_device==False):
    device = interactive.Interactive('../RTDebugger-driver/Debug/libinception.so',False)
else:
    print("\nSkipping execution on device...\n")



# possible operations
# TODO continue, somehow we must init the carry, consider CPSR etc...
operations = OrderedDict()
operations.update({"Add" : 
                     [
                       (("ADD",),
                        ("Rd","Rn","<Operand2>"),
                        ("N","Z","C","V"),
                        ("Rd:=Rn+Operand2")
                       ),
                       (("ADDS",),
                        ("Rd","Rn","<Operand2>"),
                        ("N","Z","C","V"),
                        ("Rd:=Rn+Operand2")
                       ),
                       (("ADC","ADCS"),
                        ("Rd","Rn","<Operand2>"),
                        ("N","Z","C","V"),
                        ("Rd:=Rn+Operand2+Carry")
                       ),
                       (("ADD",),
                        ("Rd","Rn","#<imm12>"),
                        (),
                        ("Rd:=Rn+imm12")
                       )
                     ]
                   })
#operations.update({"Subtract" : 
#                     [
#                       (("SUB","SUBS"),
#                        ("Rd","Rn","<Operand2>"),
#                        ("N","Z","C","V"),
#                        ("Rd:=Rn-Operand2")
#                       ),
#                       (("SBC","SBCS"),
#                        ("Rd","Rn","<Operand2>"),
#                        ("N","Z","C","V"),
#                        ("Rd:=Rn-Operand2-NOT(Carry)")
#                       ),
#                        (("SUB",),
#                        ("Rd","Rn","#<imm12>"),
#                        ("N","Z","C","V"),
#                        ("Rd:=Rn-imm12")
#                       )
#                     ]
#                   })
#
# possible operand2
# TODO continue, more values are possible, imm8 should be imm8m
operand2 = ( "#<imm8>", "Rn" )

## expanding Operand2
operations_expanded = OrderedDict()
for operation,suboperations in operations.items():
  #print (operation)
  suboperations_expanded = []
  for instructions,operands,updates,actions in suboperations:
      #print (instructions,operands,updates,actions)
      expanded = False
      for idx,operand in enumerate(operands):
          if operand == "<Operand2>":
              expanded = True
              for op in operand2:
                  #operands_expanded = operands + (op,)
                  tmp = list(operands)
                  tmp[idx]=op
                  operands_expanded = tuple(tmp)
                  suboperation_expanded = (instructions,operands_expanded,updates,actions)
                  suboperations_expanded.append(suboperation_expanded)
      if expanded == False:
          suboperations_expanded.append((instructions,operands,updates,actions))
  operations_expanded.update({operation : suboperations_expanded})

# functions to generate the test code

# generate init of a 32 bit reg
# be sure that val is an integer on 32 bits
def append_init_reg_strings(init_strings,Rn,Rn_val):
    # mov+sh not working
   # for sh in range(0,32,8):
   #     masked_val = (Rn_val & (0x000000ff << sh))>>sh
   #     init_strings.append("mov R%d,#0x%02x,#%d"%(Rn,masked_val,sh))
    init_strings.append("mov R%d,#0x%02x"%(Rn,Rn_val))

def append_init_carry_in(init_strings,carry_in):
    print ("Init carry in not supported yet")
    pass

# generate C code with inline ASM
def generate_test_code(init_strings,inst_string,return_string,id):
    # generate the test code
    with open('%s/main%d.c'%(folder,id),mode='wt') as main_file:
        main_file.write("#include <stdlib.h>\n")
        main_file.write("__attribute__((naked))\n")
        main_file.write("void main(void){\n")
       
        # input operands
        for init_string in init_strings:
            if init_string != "":
                main_file.write('  __asm volatile("'+init_string+'"); \n')
        
        # instruction under test
        if(inst_string != ""):
            main_file.write('  __asm volatile("'+inst_string+'");\n')
        
        # return stuff
        if(return_string != ""):
            main_file.write('  __asm volatile("'+return_string+'");\n')
        
        main_file.write("  #ifndef KLEE\n")
        main_file.write("  while(1);\n")
        main_file.write("  #else\n")
        main_file.write('  __asm volatile("bx lr");\n')
        main_file.write("  #endif\n")
        main_file.write("}\n")
    main_file.close

def execute_on_device_and_dump(id,changed_regs):
    # execute on the real device
    # and dump the differencies in the values of the registers before and after
    # execution
    device.halt()
    device.load_binary_in_sram('%s/main%d.bin'%(folder,id),0x10000000)
    device.write_reg(15,0x10000000) # PC
    #device.write_reg(13,0x10000000) # SP
    device.clear_all_regs()
    regs_initial = device.dump_all_regs()
    device.resume()
    time.sleep(0.01)
    device.halt()
    regs_final = device.dump_all_regs()
    with open('%s/reg_diff%d.log'%(folder,id),mode='wt') as reg_diff_file:
        #reg_diff_file.write("test\n")
        for (initial_name,initial_val),(final_name,final_val) in zip(regs_initial.items(),regs_final.items()):
            # print("%d %d\n"%(initial_val,final_val))
            if(final_val != initial_val or \
                list(device.regs.keys()).index(final_name) in changed_regs):             
                if(initial_name != "PC"):
                    reg_diff_file.write("%s\n%d\n"%(final_name,final_val))
                #elif(initial_name == "CPSR"):
                #    reg_diff_file.write("%s\n%d\n"%(final_name,final_val))
        reg_diff_file.close


# test generation
# TODO continue
id = 0
for i in range(0,tests_per_instruction):
    for operation,suboperations in operations_expanded.items():
      #print (operation)
      for instructions,operands,updates,actions in suboperations:
          #print (instructions)
          for instruction in instructions:
              changed_regs = []
              if(updates != ()):
                  changed_regs.append(list(device.regs.keys()).index('CPSR'))
              init_strings = []
              inst_string = instruction
              return_string = ""
              for operand in operands:
                  #print(operand)
                  if operand == "Rd":
                     Rd = random.randint(0,12)
                     inst_string += " R%d"%(Rd)
                     changed_regs.append(Rd)
                     #return_string += "mov r0,r%d"%(Rd)
                  elif operand == "Rn":
                     Rn = random.randint(0,12)
                     # 32 not supported yet
                     #Rn_val = random.randint(0,2**32-1)
                     Rn_val = random.randint(0,2**8-1)
                     append_init_reg_strings(init_strings,Rn,Rn_val)
                     inst_string += ", R%d"%(Rn)
                     # only MSB because of bug in write reg 32 bits...
                     changed_regs.append(Rn)
                  elif operand == "#<imm8>":
                     imm8_val = random.randint(0,2**8-1)
                     inst_string += ", #0x%02x"%(imm8_val)
                  elif operand == "#<imm12>":
                     imm12_val = random.randint(0,2**12-1)
                     inst_string += ", #0x%03x"%(imm12_val)
              # implicit operand
              if actions.find("Carry") > 0:
                  # carry_in is a source operand
                  carry_in = random.randint(0,1)
                  append_init_carry_in(init_strings,carry_in)

              # generate c code
              generate_test_code(init_strings,inst_string,return_string,id)
              
              # compile the code for the real device
              os_run.run_catch_error('make FOLDER=%s ID=%d'%(folder,id),cont)
    
              # execute on the real hw
              if(no_device==False):
                  execute_on_device_and_dump(id,changed_regs)
    
              if(no_device == False):
                  os_run.run_catch_error('cat %s/reg_diff%d.log'%(folder,id),cont)
              
              id += 1
              #input("Press any key to continue")

ldrstr_instructions = ldrstr.generate_ldrstr(seed)
for i in range(0,tests_per_instruction):
    for ldrstr_instr in ldrstr_instructions:
        print(ldrstr_instr)
        generate_test_code(["mov r12,#1"],"str r12,[sp,#4]!","",id)
        #with open('%s/main%d.c'%(folder,id),mode='wt') as main_file:
        #    main_file.write("#include <stdlib.h>\n")
        #    main_file.write("__attribute__((naked))\n")
        #    main_file.write("void main(void){\n")
        #    #main_file.write('  __asm volatile("%s");\n'%(ldrstr_instr))
        #    main_file.write('  __asm volatile("mov r0,#1");\n')
        #    main_file.write('  __asm volatile("add r1,r1,#1");\n')
        #    main_file.write('  __asm volatile("bx lr");\n')
        #    main_file.write("}\n")
        #main_file.close
        # compile the code for the real device
        os_run.run_catch_error('make FOLDER=%s ID=%d'%(folder,id),cont)
        # run on the real device and dump
        execute_on_device_and_dump(id,[])
        device.halt()
        device.display_all_regs()
        device.read(0x10000854)
        device.resume()
        id += 1
 

with open('%s/Ntests'%(folder),mode='wt') as Ntests_file:
    Ntests_file.write("%d\n"%(id))
Ntests_file.close

sys.exit(0)


