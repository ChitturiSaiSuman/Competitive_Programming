from bisect import insort
from math import ceil
from heapq import heapify,heappop,heappush,heappushpop,heapreplace,merge,nlargest,nsmallest
n,k=map(int,input().split())
l=list(map(int,input().split()))
l=[-i for i in l]
heapify(l)
#print(l)
for i in range(k):
    temp=heappop(l)
    #print(temp)
    heappush(l,ceil(temp/2))
    #print(l)
print(-sum(l))