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
    l,r=map(int,input().split())
    sum1,sum2=0,0
    if r%2==0:
        n1=r//2+1
        sum1=(n1*(n1+1)*(2*n1+1))//3
        sum1-=1+(r//2+1)**2
    else:
        n1=r//2+1
        sum1=(n1*(n1+1)*(2*n1+1))//3
        sum1-=1
    l-=1
    if l%2==0:
        n1=l//2+1
        sum2=(n1*(n1+1)*(2*n1+1))//3
        sum2-=1+(r//2+1)**2
    else:
        n1=r//2+1
        sum2=(n1*(n1+1)*(2*n1+1))//3
        sum2-=1
    print((sum1-sum2)%(10**9+7))