"""
 _____   _    _   __    __     ____     __    _
/ ____| | |  | | |  \  /  |   /    \   |  \  | |
| |___  | |  | | |   \/   |  /   _  \  | . \ | |
\____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
____| | | \__/ | | |    | | |   __   | | | \ ` |
|_____/ \______/ |_|    |_| |__|  |__| |_|  \__|

"""
"""
Template by Sai Suman Chitturi
Linkedin: https://www.linkedin.com/in/sai-suman-chitturi-9727a2196/
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

mod = 10**9+7
lcm = lambda x,y: ((x*y)//gcd(x,y))
inverse = lambda x: (pow(x,mod-2,mod))
add = lambda x,y: (x%mod+y%mod)%mod
sub = lambda x,y: ((x%mod-y%mod)+mod)%mod
mul = lambda x,y: ((x%mod)*(y%mod))%mod
setBitCount = lambda x: bin(x).count("1")
sumOfDigits = lambda x: sum([int(i) for i in str(x)])

size = 10**6+1

setrecursionlimit(10**6)

class Graph:
    def __init__(self,V,l):
        self.V = V
        self.graph = defaultdict(list)
        self.parentList = l
    def addEdge(self,a,b):
        self.graph[a].append(b)
    def solve(self):
        ans = 0
        start = 0
        distance = [10**9]*(self.V)
        visited = [False]*(self.V)
        queue = [start]
        visited[start] = True
        distance[start] = 0
        while queue:
            start = queue.pop(0)
            for friend in self.graph[start]:
                if not visited[friend]:
                    visited[friend] = True
                    queue.append(friend)
                    distance[friend] = min(distance[start]+1,distance[friend])
        ans = max(distance)
        print(ans,end=": ")
        parent = defaultdict(int)
        for i in range(1,self.V):
            if distance[i]==ans:
                print(i,end=" ")
                parent[self.parentList[i-1]]+=1
        answer2 = max(parent.values())
        print(answer2,end=", ")
        answer = ans+answer2
        final = (answer*(answer+1))//2
        final -= (answer2*(answer2+1))//2
        final+=1
        return final


        

def solve():
    pass

def main():
    io = IO()
    testcases = 0
    if testcases == 0:
        testcases = io.nextInt()

    for test in range(testcases):
        # io.write("Case #%d: "%(test+1),end="")
        n = io.nextInt()
        l = io.List()
        g = Graph(n,l)
        for i in range(n-1):
            g.addEdge(l[i]-1,i+1)
        # print(g.graph)
        io.write(g.solve())

class IO:
    def next(self):
        return stdin.readline().strip()
    def String(self):
        return self.next()
    def nextInt(self):
        return int(self.next())
    def Int(self):
        return self.nextInt()
    def nextFloat(self):
        return float(next())
    def Float(self):
        return self.nextFloat()
    def nextList(self):
        return list(map(int,self.next().split()))
    def List(self):
        return self.nextList()
    def nextTuple(self):
        return tuple(map(int,self.next().split()))
    def Tuple(self):
        return self.nextTuple()
    def print(self,*obj,sep=" ",end='\n'):
        string = sep.join([str(item) for item in obj])+end
        stdout.write(string)
    def write(self,*obj,sep=" ",end="\n"):
        self.print(*obj,sep=sep,end=end)

main()