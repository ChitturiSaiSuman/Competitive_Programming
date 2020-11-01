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
    count=dict()
    for i in input():
        try:
            count[i]+=1
        except:
            count[i]=1
    if all([count[i]%2==0 for i in count]):
        print("YES")
    else:
        print("NO")