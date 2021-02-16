"""
Author: Chitturi Sai Suman
Created: 2021-02-16 12:41:02
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

#  _____   _    _   __    __     ____     __    _
# / ____| | |  | | |  \  /  |   /    \   |  \  | |
# | |___  | |  | | |   \/   |  /   _  \  | . \ | |
# \____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
# ____| | | \__/ | | |    | | |   __   | | | \ ` |
# |_____/ \______/ |_|    |_| |__|  |__| |_|  \__|
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

shit = 998244353
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

def abort():
    raise AssertionError("Abort Called")

def preCompute():

    return

def solve():
    io = IO()
    editor = Editor()
    for i in range(io.Int()):
        inputs = io.nextStrings()
        if len(inputs) == 2:
            if inputs[0] == '1':
                editor.append(inputs[1])
            elif inputs[0] == '2':
                editor.delete(int(inputs[1]))
            else:
                io.write(editor.get(int(inputs[1])))
        else:
            editor.undo()
        # io.debug(editor.text)

def main():
    io = IO()
    testcases = 1
    if testcases == 0:
        testcases = io.nextInt()
    preCompute()

    for test in range(testcases):
        # io.write("Case #%d: "%(test+1),end="")
        
        solve()

class Editor:
    def __init__(self):
        self.text = []
        self.performed = []

    def append(self, suffix, undo = False):
        self.text.extend([i for i in suffix])
        if not undo:
            self.performed.append(("append", suffix))

    def delete(self, k, undo = False):
        popped = []
        for i in range(k):
            popped.append(self.text.pop())
        popped = popped[::-1]
        if not undo:
            self.performed.append(("delete", popped))

    def get(self, k):
        return self.text[k-1]
        
    def undo(self):
        action, object = self.performed.pop()
        if action == "append":
            self.delete(len(object), True)
        else:
            self.append(object, True)



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
        return float(self.next())
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
    def yes(self):
        self.write("yes")
    def Yes(self):
        self.write("Yes")
    def YES(self):
        self.write("YES")
    def no(self):
        self.write("no")
    def No(self):
        self.write("No")
    def NO(self):
        self.write("NO")

main()