"""
 _____   _    _   __    __     ____     __    _
/ ____| | |  | | |  \  /  |   /    \   |  \  | |
| |___  | |  | | |   \/   |  /   _  \  | . \ | |
\____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
____| | | \__/ | | |    | | |   __   | | | \ ` |
|_____/ \______/ |_|    |_| |__|  |__| |_|  \__|

"""
"""
Template by Sai Suman Chitturi.
Inspired by Money Heist - "I don't care at all. I am lost."
Hackerrank: skynetasspyder
Codechef: suman_18733097
Codeforces: saisumanchitturi
Github: ChitturiSaiSuman
Hackerearth: chitturi7
SPOJ: Sai Suman Chitturi @out_of_bound
"""
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

setrecursionlimit(10**6)

def sieve(n):
    primes = [False]*n
    for i in range(3,n,2):
        primes[i] = True
    for i in range(3,int(sqrt(n))+1,2):
        if primes[i]:
            for j in range(i*i,n,i):
                primes[j] = False
    primes[2] = True
    return [i for i in range(n) if primes[i]]

def brute(l,n):
    primes = sieve(100)
    print(primes)
    mod = 10**9+7
    numerator = 1
    denominator = 1
    for i in range(n):
        numerator *= (pow(primes[i],l[i]+1)-1)
        denominator *= (primes[i]-1)
    print("Divisible: ",numerator%denominator == 0)
    answer1 = (numerator//denominator)%mod
    answer = (numerator*pow(denominator,mod-2,mod))%mod
    print("answer1==answer2: ",answer==answer1)
    # answer = (numerator//denominator)%mod
    return answer
def optim(l,n):
    primes = sieve(100)
    print(primes)
    mod = 10**9+7
    inverse = lambda x: (pow(x,mod-2,mod))
    mul = lambda x,y: ((x%mod)*(y%mod))%mod
    ans = 1
    for i in range(n):
        ans *= mul(pow(primes[i],l[i]+1,mod)-1,inverse(primes[i]-1))
        ans%=mod
    return ans
def main():
    mod = 10**9+7
    size = 10**6+1
    lcm = lambda x,y: ((x*y)//gcd(x,y))
    inverse = lambda x: (pow(x,mod-2,mod))
    add = lambda x,y: (x%mod+y%mod)%mod
    sub = lambda x,y: ((x%mod-y%mod)+mod)%mod
    mul = lambda x,y: ((x%mod)*(y%mod))%mod
    set_bit_count = lambda x: bin(x).count("1")
    sum_of_digits = lambda x: sum([int(i) for i in str(x)])
    
    for test in range(int(input())):
        n = int(input())
        l = list(map(int,input().split()))
        print(n)
        print(l)
        ans1 = brute(l,n)
        ans2 = optim(l,n)
        print(ans1,ans2)
        print(ans1==ans2)

main()