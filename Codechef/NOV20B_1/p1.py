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


def solve():
    pass

# cook your dish here
# cook your dish here
t=int(input())
while t:
    n,k=map(int,input().split())
    l=list(input())
    count=0
    iron=-1
    magnet=-1
    original=l
    cross=-1
    sheets=0
    sheetindex=-1
    for i in range(n):
        if(original[i]=="M"):
            magnet=i
        if(original[i]=="I"):
            iron=i
        if(original[i]=="X" and (magnet!=-1 or iron!=-1)):
            cross=i
        if((iron!=-1 or magnet!=-1) and original[i]==":"):
            sheets+=1
            sheetindex=i
        if(iron>=0) and magnet>=0:
            if (cross!=-1) and ((magnet<cross and cross<iron) or (iron<cross and cross<magnet)):
                if(magnet<iron):
                    magnet=-1
                else:
                    iron=-1
                cross=-1
                continue
            else:
                if(((magnet<sheetindex and sheetindex<iron) or (iron<sheetindex and sheetindex<magnet))):
                    p=k+1-abs(iron-magnet)-sheets
                else:
                    sheets=0
                    p=k+1-abs(iron-magnet)-sheets
                if(p>0):
                    count+=1
                    sheets=0
                    magnet=-1
                    iron=-1
    print(count)
    t-=1


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

# main()