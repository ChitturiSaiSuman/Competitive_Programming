"""
Author: Chitturi Sai Suman
Created: 2021-02-02 11:22:38
"""
import sys
import os
import time
program_to_be_executed = sys.argv[1]
os.system("clear")
print("Debug Output:")
print("*"*50)
this = time.time()
if ".java" in program_to_be_executed:
    os.system("javac "+program_to_be_executed)
    this = time.time()
    os.system("java Main < in.in > out.out")
elif ".cpp" in program_to_be_executed:
    os.system("g++ -o runner "+program_to_be_executed+" -lm")
    this = time.time()
    os.system("./runner < in.in > out.out")
elif ".c" in program_to_be_executed:
    os.system("gcc -o runner "+program_to_be_executed+" -lm")
    this = time.time()
    os.system("./runner < in.in > out.out")
elif ".py" in program_to_be_executed:
    this = time.time()
    os.system("python3 "+program_to_be_executed+" < in.in > out.out")
print("*"*50)
with open("output.out","r") as output:
    s = output.read()
    if len(s)>1000:
        print("Huge Output")
    else:
        print("Output:")
        print("*"*50)
        os.system("cat out.out")
        print("*"*50)
print("Time: ",time.time()-this)
print("Done!")
for file in os.listdir():
    if "runner" in file or ".class" in file:
        os.system("rm "+file)
