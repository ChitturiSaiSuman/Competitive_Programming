for test in range(int(input())):
    n,b,m=map(int,input().split())
    l=list(map(int,input().split()))
    ans=1
    prev=l[0]//b
    for i in range(1,m):
        temp=l[i]
        if temp//b!=prev:
            ans+=1
            prev=temp//b
    print(ans)