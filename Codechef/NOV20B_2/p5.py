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
from numpy.core import numeric

mod = 998244353
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
    testcases = 0
    if testcases == 0:
        testcases = io.nextInt()

    for test in range(testcases):
        # io.write("Case #%d: "%(test+1),end="")
        n = io.Int()
        l = io.List()
        num = 0
        den = 1
        minimum = l[0]
        prev = 1
        for i in l:
            den = mul(den,i+1)
            minimum = min(minimum,i)
            prev = mul(prev,i-1)
        total = den
        print("Min: ",minimum)
        prev = sub(total,prev)
        # io.debug(den,minimum,prev)
        for i in range(1,(minimum+1)//2-1):
            temp = 1
            for j in range(n):
                temp = mul(temp,l[j]-1-i*2)
            print("Prev,Temp = %d, %d"%(prev,temp))
            print("Sub: ",sub(prev,temp))
            num = add(num,i*sub(prev,temp))
            prev = temp
            # prev = num
        temp = 1
        for i in range(n):
            temp = mul(temp,l[i]+1-2*(minimum//2))
        print("Temp: ",temp)
        temp = mul(minimum//2,temp)
        num = add(num,temp)
        print(num,den)
        io.write(mul(num,inverse(total)))


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