from math import sqrt
from sys import stdin,stdout
size=10**6+2
prime=[0]*size
count=[0]*size
for i in range(3,size,2):
    prime[i]=1
prime[2]=1
for i in range(3,int(sqrt(size)),2):
    if prime[i]==1:
        for j in range(i*i,size,i):
            prime[j]=0
for i in range(1,size):
    count[i]=count[i-1]+prime[i]
mod=10**9+7
for test in range(int(input())):
    n=int(stdin.readline())
    stdout.write(str(0 if n==1 else pow(2,count[n]-1,mod))+'\n')