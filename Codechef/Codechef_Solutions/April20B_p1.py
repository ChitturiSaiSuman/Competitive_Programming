from sys import stdin,stdout
mod=10**9+7
t=int(stdin.readline())
while t>0:
    n=int(stdin.readline())
    l=sorted(map(int,stdin.readline().split()),reverse=True)
    ans=0
    for i in range(n):
        if l[i]-i>0:
            ans+=(l[i]-i)
        else:
            break
    ans=ans%mod
    stdout.write(str(ans)+'\n')
    t-=1
