"""
A part of this code is taken from https://www.geeksforgeeks.org/subsequence-no-0-1/
Created: 2021-01-30 20:54:37
"""
# 
# Linkedin: https://www.linkedin.com/in/sai-suman-chitturi-9727a2196/
# Hackerrank: https://www.hackerrank.com/skynetasspyder?hr_r=1
# Codechef: https://www.codechef.com/users/suman_18733097
# Codeforces: http://codeforces.com/profile/saisumanchitturi
# Github: https://github.com/ChitturiSaiSuman
# Hackerearth: https://www.hackerearth.com/@chitturi7
# SPOJ: Sai Suman Chitturi @out_of_bound
# 
# 
#  _____   _    _   __    __     ____     __    _
# / ____| | |  | | |  \  /  |   /    \   |  \  | |
# | |___  | |  | | |   \/   |  /   _  \  | . \ | |
# \____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
# ____| | | \__/ | | |    | | |   __   | | | \ ` |
# |_____/ \______/ |_|    |_| |__|  |__| |_|  \__|
# 
#
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

def solve():
    return

# Python 3 program to find longest subsequence 
# such that there is no 0 after 1. 

def maxSubseq(vec, n): 
	# Store the count of number of ones 
	# from right to left in the array 
	suffix = 0
	i = n-1
	while(i >= 0): 
		if (vec[i] == 1): 
			suffix += 1
			vec[i] = suffix 
		i -= 1
			
	# Traverse from left to right, keep count 
	# of 0s and for every 0, check number of 
	# 1s after it. Update the result if needed. 
	res = 0
	zero = 0
	for i in range(0,n,1): 
		if (vec[i] == 0): 
			zero += 1
	
		# Checking the maximum size 
		if (vec[i] > 0): 
			res = max(res, zero + vec[i]) 
	
	# Checking the maximum size 
	return max(res, zero) 





def main():
    io = IO()
    testcases = 0
    if testcases == 0:
        testcases = io.nextInt()
    preCompute()

    for test in range(testcases):
        # io.write("Case #%d: "%(test+1),end="")
        n = io.Int()
        l = io.String()
        l = [int(i) for i in l]
        io.write(n - maxSubseq(l,n))
        # solve()



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