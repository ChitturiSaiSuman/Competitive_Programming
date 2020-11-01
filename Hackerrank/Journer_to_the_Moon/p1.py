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
# from numpy import dot,trace,argmax,argmin,array,cumprod,cumsum,matmul

setrecursionlimit(10**6)

def cumsum(l):
    s = [l[0]]
    for i in range(1,len(l)):
        s.append(s[-1]+l[i])
    return s[::-1]

class Graph():
    def __init__(self,V,E):
        self.V = V
        self.E = E
        self.graph = defaultdict(list)
    def addEdge(self,a,b):
        self.graph[a].append(b)
        self.graph[b].append(a)
    def solve(self):
        visited = [False]*self.V
        def bfs(start):
            queue = [start]
            visited[start] = True
            c = 0
            while queue:
                start = queue.pop(0)
                c+=1
                for i in self.graph[start]:
                    if not visited[i]:
                        visited[i] = True
                        queue.append(i)
            return c
        i = 0
        l = []
        while i<self.V:
            if not visited[i]:
                l.append(bfs(i))
            i+=1
        s = cumsum(l)
        l = l[::-1]
        # print(s,l)
        ans = 0
        for i in range(len(l)-1):
            ans += l[i]*s[i+1]
        print(ans)


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
    
    for test in range(1):
        n,m = map(int,input().split())
        g = Graph(n,m)
        for i in range(m):
            a,b = map(int,input().split())
            g.addEdge(a,b)
        g.solve()

main()