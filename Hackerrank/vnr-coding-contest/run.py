import sys
import os
import time
this = time.time()
program_to_be_executed = sys.argv[1]
os.system("clear")
if ".java" in program_to_be_executed:
    os.system("javac "+program_to_be_executed)
    os.system("java Main "+"< input.txt > output.txt")
elif ".cpp" in program_to_be_executed:
    os.system("g++ -o runner "+program_to_be_executed+" -lm")
    os.system("./runner "+"< input.txt > output.txt")
elif ".c" in program_to_be_executed:
    os.system("gcc -o runner "+program_to_be_executed+" -lm")
    os.system("./runner "+"< input.txt > output.txt")
elif ".py" in program_to_be_executed:
    os.system("python3 "+program_to_be_executed+" < input.txt > output.txt")
with open("output.txt","r") as output:
    s = output.read()
    if len(s)>100:
        print("Huge Output")
    else:
        print("Output:")
        print("*"*50)
        os.system("cat output.txt")
        print("*"*50)
print("Time: ",time.time()-this)
print("Done!")