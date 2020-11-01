from sys import stdin,stdout
from math import sqrt
size = 2000001
prime = [False]*size
answer = [0]*size
def precompute():
    global size,prime,answer
    prime[2]=True
    for i in range(3,size,2):
        prime[i]=True
    for i in range(3,int(sqrt(size))+1,2):
        if prime[i]:
            for j in range(i*i,size,i):
                prime[j]=False
    i=2
    k=2
    while (i<size):
        while(i<size and not prime[i]):
            answer[i]=k
            i+=1
        k=i
        if i<size:
            answer[i]=k
        i+=1
def solve(n):
    global answer
    stdout.write(str(pow(2,answer[n]-1,10**9+7))+'\n')
precompute()
for test in range(int(stdin.readline())):
    n = int(stdin.readline())
    if n<2 or n>2*10**6:
        raise ValueError("N is out of constraints")
    solve(n)