from sys import stdin,stdout
from math import sqrt,gcd,ceil,floor,log2,log10,factorial,cos,acos,tan,atan,atan2,sin,asin,radians,degrees,hypot
from bisect import insort, insort_left, insort_right
from array import array
from functools import reduce
from itertools import combinations, combinations_with_replacement, permutations
from fractions import Fraction
from random import choice,getrandbits,randint,random,randrange,shuffle
from re import compile,findall,escape
from statistics import mean,median,mode
from heapq import heapify,heappop,heappush,heappushpop,heapreplace,merge,nlargest,nsmallest

for test in range(int(stdin.readline())):
    n=int(input())
    ans=0
    temp1=0
    temp2=0
    l=list(map(int,input().split()))
    for i in range(n):
        for j in range(i+1,n):
            num1,num2=l[i],l[j]
            bin1=bin(num1)
            bin2=bin(num2)
            ans1=bin1[2:]+bin2[2:]
            ans2=bin2[2:]+bin1[2:]
            ans1=int(ans1,2)
            ans2=int(ans2,2)
            if abs(ans1-ans2)>ans:
                ans=abs(ans1-ans2)
                temp1=num1
                temp2=num2
    print(ans,temp1,temp2)