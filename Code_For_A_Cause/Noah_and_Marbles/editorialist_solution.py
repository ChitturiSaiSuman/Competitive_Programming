from functools import reduce
import math
t=int(input())
for i in range(t):
    n,x=map(int,input().split())
    a=list(map(int,input().split()))
    count=dict()
    for i in count:
        try:
            count[i]+=1
        except:
            count[i]=1
    if any([count[i]>1 for i in count]):
        raise ValueError("Constraints Mismatch")
    print(reduce(lambda x,y: math.gcd(x,y),[abs(i-x) for i in a]))