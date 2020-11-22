from math import sqrt,gcd,log2,log10,floor,ceil,factorial
from sys import stdin,stdout
for test in range(int(input())):
    s,n=map(int,input().split())
    ans=s//n
    s=s%n
    if s%2==1:
        if s==1:
            ans+=1
        else:
            ans+=2
    elif s>1:
        ans+=1
    print(ans)