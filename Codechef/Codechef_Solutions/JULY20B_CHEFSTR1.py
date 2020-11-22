for test in range(int(input())):
    n=int(input())
    ans=0
    l=list(map(int,input().split()))
    for i in range(n-1):
        ans+=abs(l[i]-l[i+1])-1
    print(ans)