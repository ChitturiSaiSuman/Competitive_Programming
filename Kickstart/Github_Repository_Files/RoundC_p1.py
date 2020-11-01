t=int(input())
for test in range(t):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    ans=0
    i=0
    while i<n:
        if l[i]==k:
            while i<n-1 and l[i]-1==l[i+1]:
                i+=1
            if l[i]==1:
                ans+=1
        i+=1
    print("Case #%d: %d"%(test+1,ans))