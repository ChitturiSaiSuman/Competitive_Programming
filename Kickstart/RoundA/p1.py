from math import gcd,sqrt,log2,log10,factorial
import heapq
from sys import stdin,stdout
t=int(input())
case=1
while t>0:
    n,k=map(int,input().split())
    l=sorted(map(int,input().split()))
    c=0
    for i in range(n):
        if l[i]<=k:
            k-=l[i]
            c+=1
    print("Case #%d: "%(case),c)
    case+=1
    t-=1
