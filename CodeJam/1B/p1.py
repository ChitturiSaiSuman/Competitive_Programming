t=int(input())
while t>0:
    x,y=map(int,input().split())
    bin1=bin(x)[2:]
    bin2=bin(y)[2:]
    used=[True for i in range(32)]
    for i in range(
