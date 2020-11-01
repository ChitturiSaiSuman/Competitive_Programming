size=10**4+1
l=[]
for i in range(1,size):
    b=bin(i)[2:]
    b=b.replace('1','9')
    l.append(b)
for i in range(int(input())):
    n=int(input())
    for j in l:
        if int(j)%n==0:
            print(j)
            break