import os
import sys
program1 = sys.argv[1]
program2 = sys.argv[2]
os.system("python3 run.py "+program1)
os.system("clear")
os.system("cp output.txt output1.txt")
os.system("python3 run.py "+program2)
os.system("clear")
os.system("cp output.txt output2.txt")
output1 = ""
output2 = ""
with open("output1.txt") as out:
    output1+=out.read()
with open("output2.txt") as out:
    output2+=out.read()
if output1!=output2:
    print("Unequal Outputs")
    output1 = list(map(str,output1.split('\n')))
    output2 = list(map(str,output2.split('\n')))
    print("Output1")
    print(output1)
    print("Output2")
    print(output2)
else:
    print("Outputs Matched")