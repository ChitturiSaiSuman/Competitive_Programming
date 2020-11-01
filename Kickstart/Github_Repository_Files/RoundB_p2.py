t=int(input())
case_count=1
while t>0:
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    ans=(l[-1])*(k//l[-1])
    for i in range(n-2,-1,-1):
        ans=l[i]*(ans//l[i])
    print("Case #%d: %d"%(case_count,ans))
    case_count+=1
    t-=1
