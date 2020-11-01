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
    def __init__(self,V):
        self.V = V
        self.graph = defaultdict(list)
    def addEdge(self,a,b):
        self.graph[a].append(b)
    def bfs(self,start):
        visited = [False]*(self.V+1)
        visited[0] = True
        queue = []
        queue.append(start)
        visited[start]=True
        while queue:
            s = queue.pop(0)
            for i in self.graph[s]:
                if not visited[i]:
                    visited[i]=True
                    queue.append(i)
        return len(visited)-visited.count(True)
    def solve(self):
        for i in range(1,self.V+1):
            temp = len(self.graph[i])
            if temp>2:
                raise ValueError("Error")
        ans = 10**10
        # ind = 0
        for i in range(1,self.V+1):
            temp = self.bfs(i)
            if temp<ans:
                ans = temp
                # ind = i
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
    
    for test in range(int(input())):
        n = int(input())
        g = Graph(n)
        for i in range(n-1):
            a,b = map(int,input().split())
            g.addEdge(a,b)
        g.solve()
main()