from fractions import Fraction
from math import sqrt
n=int(input())
count=dict()
for i in range(n):
    x,y,v=map(int,input().split())
    dist=x*x+y*y
    time=dist/(v*v)
    try:
        count[time]+=1
    except:
        count[time]=1
ans=0
for i in count:
    ans+=(count[i]*(count[i]-1))//2
print(ans)