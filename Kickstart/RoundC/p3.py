from math import sqrt
t=int(input())
for test in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    ans=0
    for i in range(n):
        s=0
        for j in range(i,n):
            s+=l[j]
            if s>=0 and int(sqrt(s))==sqrt(s):
                ans+=1
    print("Case #%d: %d"%(test+1,ans))