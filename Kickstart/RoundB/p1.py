import math
t=int(input())
case_count=1
while t>0:
    n=int(input())
    l=list(map(int,input().split()))
    ans=0
    for i in range(1,n-1):
        if l[i]>l[i-1] and l[i]>l[i+1]:
            ans+=1
    print("Case #%d: %d"%(case_count,ans))
    case_count+=1
    t-=1
