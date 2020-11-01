from sys import stdin,stdout
t = int(stdin.readline())
if t>10**5:
    raise ValueError("Invalid Number of Test Cases")
for test in range(t):
    s = input()
    length = len(s)
    if length > 10**6:
        raise ValueError("Length exceeded")
    if length>1:
        num = int(s[-2]+s[-1])
    else:
        num = int(s[-1])
    if num%4==0:
        stdout.write(s+'\n')
    elif num%4==1:
        stdout.write("1\n")
    elif num%4==2:
        stdout.write(s[:length-1]+str(int(s[-1])+1)+'\n')
    else:
        stdout.write("0\n")