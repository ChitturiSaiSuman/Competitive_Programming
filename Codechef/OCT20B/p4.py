from sys import stdin,stdout,stderr,setrecursionlimit
from math import pi,sqrt,gcd,ceil,floor,log2,log10,factorial
from math import cos,acos,tan,atan,atan2,sin,asin,radians,degrees,hypot
from bisect import insort,insort_left,insort_right,bisect_left,bisect_right,bisect
from functools import reduce
from itertools import combinations,combinations_with_replacement,permutations
from fractions import Fraction
from random import choice,getrandbits,randint,random,randrange,shuffle
from re import compile,findall,escape,search,match
from statistics import mean,median,mode
from heapq import heapify,heappop,heappush,heappushpop,heapreplace,merge,nlargest,nsmallest
from collections import deque,OrderedDict,defaultdict
from collections import Counter,namedtuple,ChainMap,UserDict,UserList,UserString
from numpy import dot,trace,argmax,argmin,array,cumprod,cumsum,matmul

def scan_list():
    return list(map(int,stdin.readline().split()))

def scan_tuple():
    return map(int,stdin.readline().split())

def scan_int():
    return int(stdin.readline())

mod = 10**9+7
size = 10**6+1
lcm = lambda x,y: ((x*y)//gcd(x,y))
inverse = lambda x: (pow(x,mod-2,mod))
add = lambda x,y: (x%mod+y%mod)%mod
sub = lambda x,y: ((x%mod-y%mod)+mod)%mod
mul = lambda x,y: ((x%mod)*(y%mod))%mod
set_bit_count = lambda x: bin(x).count("1")
sum_of_digits = lambda x: sum([int(i) for i in str(x)])

setrecursionlimit(10**6)
# ***********************************************************************

def solve():
    pass

def main():
    
    for test in range(int(input())):
        N,X,p,k = map(int,input().split())
        l = sorted(map(int,input().split()))
        k-=1
        p-=1
        if k<=p:
            

main()