from sys import stdin,stdout
from math import sqrt,log2,log10,ceil,floor
from random import randint
from bisect import insort
for test in range(int(input())):
    print("Case #%d: "%(test+1),end="")
    n = int(stdin.readline())
    l = list(map(int,stdin.readline().split()))
    ans = 0
    if n<=4:
        print(0)
        continue
    i = 1
    while i<n:
        count = 0
        j = i
        while j<n and j<i+4:
            if l[j]>l[j-1]:
                count+=1
            j+=1
        if count==4:
            ans+=1
            i+=4
        else:
            count = 0
            j = i
            while j<n and j<i+4:
                if l[j]<l[j-1]:
                    count+=1
                j+=1
            if count==4:
                ans+=1
                i+=4
            else:
                i+=1
    print(ans)