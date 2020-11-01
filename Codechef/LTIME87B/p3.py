"""
Template by Sai Suman Chitturi.
TALK IS CHEAP. SHOW ME THE CODE.
Hackerrank: skynetasspyder
Codechef: suman_18733097
Codeforces: saisumanchitturi
Github: ChitturiSaiSuman
Hackerearth: chitturi7
SPOJ: Sai Suman Chitturi @out_of_bound
"""

from sys import stdin,stdout,stderr,setrecursionlimit
from math import pi,sqrt,gcd,ceil,floor,log2,log10,factorial,cos,acos,tan,atan,atan2,sin,asin,radians,degrees,hypot
from bisect import insort,insort_left,insort_right,bisect_left,bisect_right,bisect
from functools import reduce
from itertools import combinations,combinations_with_replacement,permutations
from fractions import Fraction
from random import choice,getrandbits,randint,random,randrange,shuffle
from re import compile,findall,escape,search,match
from statistics import mean,median,mode
from heapq import heapify,heappop,heappush,heappushpop,heapreplace,merge,nlargest,nsmallest
from collections import deque,OrderedDict,defaultdict,Counter,namedtuple,ChainMap,UserDict,UserList,UserString
from numpy import dot,trace,argmax,argmin,array,cumprod,cumsum,matmul

lcm=lambda x,y: ((x*y)//(gcd(x,y)))
mod=10**9+7
size=10**6+3

for test in range(int(stdin.readline())):
    n = int(input())
    l = list(map(int,input().split()))
    if l.count(0)==1:
        print("Yes")
    else:
        mylist = []
        i=0
        while i<n:
            c=0
            while i<n and l[i]==0:
                i+=1
                c+=1
            mylist.append(c)
            while i<n and l[i]==1:
                i+=1
        mylist.sort()
        count = Counter(mylist)
        if mylist[-1]%2==0:
            print("No")
        else:
            if count[mylist[-1]]>1:
                print("No")
            else:
                if mylist[-2]>=(mylist[-1]+1)//2:
                    print("No")
                else:
                    print("Yes")