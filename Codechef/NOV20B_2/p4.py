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

mod = 2**32
lcm = lambda x,y: ((x*y)//gcd(x,y))
inverse = lambda x: (pow(x,mod-2,mod))
add = lambda x,y: (x%mod+y%mod)%mod
sub = lambda x,y: ((x%mod-y%mod)+mod)%mod
mul = lambda x,y: ((x%mod)*(y%mod))%mod
setBitCount = lambda x: bin(x).count("1")
sumOfDigits = lambda x: sum([int(i) for i in str(x)])

size = 10**6+1

setrecursionlimit(10**6)


def solve():
    pass

def main():
    io = IO()
    testcases = 1
    if testcases == 0:
        testcases = io.nextInt()

    for test in range(testcases):
        # io.write("Case #%d: "%(test+1),end="")
        n,q = io.Tuple()
        vals = io.List()
        # io.debug(n,q,vals)
        tree = Tree(n,vals)
        for i in range(n-1):
            a,b = map(int,input().split())
            tree.addEdge(a-1,b-1)
        for i in range(q):
            a,b = map(int,input().split())
            # io.debug(a,b)
            io.write(tree.solve(a-1,b-1))
        pass

class Tree:
    def __init__(self,V,vals):
        self.V = V
        self.vals = vals
        self.tree = defaultdict(list)
    def addEdge(self,a,b):
        self.tree[a].append(b)
        self.tree[b].append(a)
    def dfs(self,start,stop,path,visited):
        visited[start] = True
        path.append(start)
        if start==stop:
            return
        for i in self.tree[start]:
            if not visited[i]:
                temp = []
                self.dfs(i,stop,temp,visited)
                if len(temp)>0 and temp[-1] == stop:
                    path.extend(temp)
                    return
    def solve(self,a,b):
        path1 = []
        path2 = []
        visited1 = [False]*self.V
        visited2 = [False]*self.V
        visited1[0] = visited2[0] = True
        self.dfs(0,a,path1,visited1)
        self.dfs(0,b,path2,visited2)
        # print(path1,path2)
        ans = 0
        for i in range(len(path1)):
            ans = add(ans,mul(self.vals[path1[i]],self.vals[path2[i]]))
        return ans
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
    def debug(self,*obj,sep=" ",end='\n'):
        string = sep.join([str(item) for item in obj])+end
        stderr.write(string)
    def print(self,*obj,sep=" ",end='\n'):
        string = sep.join([str(item) for item in obj])+end
        stdout.write(string)
    def write(self,*obj,sep=" ",end="\n"):
        self.print(*obj,sep=sep,end=end)

main()