"""
 _____   _    _   __    __     ____     __    _
/ ____| | |  | | |  \  /  |   /    \   |  \  | |
| |___  | |  | | |   \/   |  /   _  \  | . \ | |
\____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
____| | | \__/ | | |    | | |   __   | | | \ ` |
|_____/ \______/ |_|    |_| |__|  |__| |_|  \__|

"""
"""
/*
Template by Sai Suman Chitturi
Linkedin: https://www.linkedin.com/in/sai-suman-chitturi-9727a2196/
Hackerrank: https://www.hackerrank.com/skynetasspyder?hr_r=1
Codechef: https://www.codechef.com/users/suman_18733097
Codeforces: http://codeforces.com/profile/saisumanchitturi
Github: https://github.com/ChitturiSaiSuman
Hackerearth: https://www.hackerearth.com/@chitturi7
SPOJ: Sai Suman Chitturi @out_of_bound
*/
"""
from sys import stdin,stdout,stderr,setrecursionlimit
from math import pi,sqrt,gcd,ceil,floor,log2,log10,factorial, trunc
from math import cos,acos,tan,atan,atan2,sin,asin,radians,degrees,hypot,pi
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
# from numpy.lib.function_base import disp

mod = 10**9+7
lcm = lambda x,y: ((x*y)//gcd(x,y))
add = lambda x,y: (x%mod+y%mod)%mod
sub = lambda x,y: ((x%mod-y%mod)+mod)%mod
mul = lambda x,y: ((x%mod)*(y%mod))%mod
setBitCount = lambda x: bin(x).count("1")
sumOfDigits = lambda x: sum([int(i) for i in str(x)])

size = 10**6+1

setrecursionlimit(10**6)

class Graph:
    def __init__(self,names):
        self.hash = defaultdict(set)
        self.graph = defaultdict(list)
        self.names = names
    def add(self,name):
        for ch in name:
            self.hash[ch].add(name)
    def finish(self):
        for i in self.hash:
            self.graph[i] = list(self.hash[i])
        # print(self.graph)
    def solve(self,ind1,ind2):
        name1 = self.names[ind1-1]
        name2 = self.names[ind2-1]
        s1 = set(name1)
        s2 = set(name2)
        for i in s1:
            if i in s2:
                return 2
        distances = []
        queue = []
        charvisited = defaultdict(bool)
        namevisited = defaultdict(bool)
        for ch in name1:
            if not charvisited[ch]:
                charvisited[ch] = True
                queue.append(self.graph[ch])
        distance = 0
        while queue:
            # print(queue)
            distance += 1
            temp = []
            while queue:
                names = queue.pop(0)
                for name in names:
                    if not namevisited[name]:
                        namevisited[name] = True
                        for ch in name:
                            if not charvisited[ch]:
                                charvisited[ch] = True
                                temp2 = []
                                for tempname in self.graph[ch]:
                                    if not namevisited[tempname]:
                                        temp2.append(tempname)
                                temp.append(temp2)
                    if name==name2:
                        distances.append(distance+1)
            queue.extend(temp)
        try:
            return min(distances)
        except:
            return -1

def solve():
    pass

def main():
    io = IO()
    testcases = 0
    if testcases == 0:
        testcases = io.nextInt()

    for test in range(testcases):
        io.write("Case #%d: "%(test+1),end="")
        n,q = io.Tuple()
        names = list(map(str,stdin.readline().strip().split()))
        g = Graph(names)
        for name in names:
            g.add(name)
        g.finish()
        ans = []
        for i in range(q):
            ind1, ind2 = io.Tuple()
            ans.append(g.solve(ind1,ind2))
        io.write(*ans)

def inverse(a,p = mod):
    return pow(a,mod-2,mod)

class IO:
    def next(self):
        return stdin.readline().strip()
    def String(self):
        return self.next()
    def nextStrings(self):
        return list(map(str,self.next().split()))
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
    def debug(self,*obj,sep=" ",end="\n"):
        string = sep.join([str(item) for item in obj])+end
        stderr.write(string)
    def print(self,*obj,sep=" ",end='\n'):
        string = sep.join([str(item) for item in obj])+end
        stdout.write(string)
    def write(self,*obj,sep=" ",end="\n"):
        self.print(*obj,sep=sep,end=end)

main()