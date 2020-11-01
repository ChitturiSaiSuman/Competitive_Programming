from sys import stdin,stdout
mod=10**9+7
t=int(stdin.readline())
while t>0:
    n,a=map(int,stdin.readline().split())
    ans=0
    whole=1
    current=a
    for i in range(1,n+1):
        ans=(ans+pow(current,whole,mod))%mod
        current=(pow(current,whole,mod)*current)%mod
        whole+=2
    stdout.write(str(ans)+'\n')
    t-=1
