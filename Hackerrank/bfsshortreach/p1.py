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

class Graph():
    def __init__(self,V,E):
        self.V = V
        self.E = E
        self.graph = defaultdict(list)
    def addEdge(self,a,b):
        self.graph[a-1].append(b-1)
        self.graph[b-1].append(a-1)
    def solve(self,start):
        start -= 1
        temp = start
        visited = [False]*(self.V)
        distance = [10**10]*(self.V)
        distance[start] = 0
        queue = [start]
        visited[start] = True
        while queue:
            start = queue.pop(0)
            for i in self.graph[start]:
                if not visited[i]:
                    visited[i] = True
                    distance[i] = min(distance[i],distance[start]+6)
                    queue.append(i)
        for i in range(len(distance)):
            if distance[i]==10**10:
                distance[i] = -1
        # print(distance)
        # print(temp)
        print(*(distance[:temp]+distance[temp+1:]))

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
        V,E = map(int,input().split())
        g = Graph(V,E)
        for i in range(E):
            a,b = map(int,input().split())
            g.addEdge(a,b)
        g.solve(int(input()))

main()