from sys import stdin,stdout
from math import sqrt,gcd,ceil,floor,log2,log10,factorial,cos,acos,tan,atan,atan2,sin,asin,radians,degrees,hypot
from bisect import insort, insort_left, insort_right, bisect_left, bisect_right, bisect
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
    l=list(map(int,input().split()))
    ind1=0
    ind2=1
    ind3=n-1
    if l[ind1]+l[ind2]<=l[ind3]:
        print(ind1+1,ind2+1,ind3+1)
    else:
        print(-1)