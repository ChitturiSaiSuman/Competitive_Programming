from math import gcd,sqrt,log2,log10,factorial
import heapq
from sys import stdin,stdout
t=int(input())
counter=1
while t>0:
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    diff=[]
    for i in range(1,n):
        diff.append(l[i]-l[i-1])
    ind=diff.index(max(diff))
    if diff[ind]%2==0:
        diff[ind]=diff[ind]//2
    else:
        value1=diff[ind]//2
        value2=value1+1
        diff.pop(ind)
        diff.append(value1)
        diff.append(value2)
    if k==1:
        print("Case #%d:"%(counter),max(diff))
        counter+=1
    t-=1
