t=int(input())
while t>0:
    n,q=map(int,input().split())
    ans=0
    a,b=map(int,input().split())
    ans+=a+abs(a-b)
    last=b
    for _ in range(q-1):
        a,b=map(int,input().split())
        ans+=abs(last-a)+abs(a-b)
        last=b
    print(ans)
    t-=1

