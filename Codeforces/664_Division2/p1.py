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
    r,g,b,w=map(int,input().split())
    if r>0 and b>0 and g>0:
        total=r+b+g
        if total%2==0:
            if [r%2,b%2,g%2].count(1)==2:
                if w%2==1:
                    print("YES")
                else:
                    print("NO")
            else:
                print("YES")
        else:
            if [r%2,b%2,g%2].count(1)==3:
                print("YES")
            else:
                if w%2==1:
                    print("NO")
                else:
                    print("YES")
    else:
        if r==0 and b==0 and g==0:
            print("YES")
        elif [r==0,b==0,g==0].count(True)==2:
            s=r+b+g
            if s%2==0:
                print("YES")
            elif w%2==0:
                print("YES")
            else:
                print("NO")
        else:
            l=[]
            if r>0:
                l.append(r)
            if g>0:
                l.append(g)
            if b>0:
                l.append(b)
            x,y=l[0],l[1]
            if x%2==0 and y%2==0:
                print("YES")
            else:
                print("NO")