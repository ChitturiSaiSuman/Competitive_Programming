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
hell = 10**9+9
inf = 10**18
lcm = lambda x,y: ((x*y)//gcd(x,y))
add = lambda x,y: (x%mod+y%mod)%mod
sub = lambda x,y: ((x%mod-y%mod)+mod)%mod
mul = lambda x,y: ((x%mod)*(y%mod))%mod
inverse = lambda x: (pow(x,mod-2,mod))
setBitCount = lambda x: bin(x).count("1")
sumOfDigits = lambda x: sum([int(i) for i in str(x)])

size = 10**6+1

setrecursionlimit(size)

def preCompute():
    return

def solve(vals):
    io = IO()
    l = [0]*len(vals)
    n = len(vals)
    count = defaultdict(int)
    c = 0
    for i in range(n-1,-1,-1):
        l[i] += sum(vals[i])
        l[i] += c
        temp = []
        for j in count:
            c -= count[j]
            temp.append(j)
            # count[j] -= j
            # if count[j] <= 0:
                # c -= 1
                # temp.append(j)
            # if count[j]<=0:
        temp2 = defaultdict(int)
        for j in temp:
            if j!=1:
                temp2[j-1] = count[j]
            del count[j]
        for j in temp2:
            count[j] = temp2[j]
            # count[j-1] += temp2
                # count.popitem(j)
        # count = temp
        for j in range(len(vals[i])):
            vals[i][j] -= 1
            if vals[i][j] > 0:
                count[vals[i][j]] += 1
                # count.append(vals[i][j])
                c += vals[i][j]
        # io.debug(c,count)
    return l
def main():
    io = IO()
    testcases = 0
    if testcases == 0:
        testcases = io.nextInt()
    preCompute()

    for test in range(testcases):
        # io.write("Case #%d: "%(test+1),end="")
        n,k = io.Tuple()
        vals = []
        for i in range(n):
            vals.append([])
        # io.debug(vals)
        # bit = BIT(n,vals)
        for i in range(k):
            a,b = io.Tuple()
            vals[b-1].append(b+1-a)
            # io.debug(vals)
        # compute(vals)
        # io.debug(vals)
        vals = solve(vals)
        io.write(*vals)

# class BIT:
#     def __init__(self,n,arr):
#         self.arr = arr
#         self.n = n
#         self.bit = [0]*(self.n+1)
#         for i in range(n):
#             ind = i
#             ind += 1
#             while ind<=self.n:
#                 self.bit[ind] += self.arr[i]
#                 ind += ind&(-ind)
#     def update(self,ind,val):
#         initial = self.arr[ind]
#         self.arr[ind] = val
#         val -= initial
#         ind += 1
#         while ind <= self.n:
#             self.bit[ind] += val
#             ind += ind&(-ind)
#     def find(self,ind):
#         s = 0
#         ind += 1
#         while ind>0:
#             s += self.bit[ind]
#             ind -= ind&(-ind)
#         return s
#     def findRange(self,ind1,ind2):
#         if ind1>ind2:
#             ind1,ind2 = ind2,ind1
#         return self.find(ind2)-self.find(ind1-1)

class IO:
    def next(self):
        return stdin.readline().strip()
    def nextLine(self):
        return self.next()
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