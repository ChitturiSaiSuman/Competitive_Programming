from random import randrange
file1=open("input09.txt","w")
file2=open("output09.txt","w")
mod = 10**9+7
fact = [ 0 for x in range(1001)]
fact[0]=1
for i in range(1,1001):
    fact[i] = i*fact[i-1]
t=randrange(1,10**5+1)
print("%d"%(t),file=file1,flush=True)
for i in range(t):
    n=randrange(1,10**3+1)
    m=randrange(1,10**3+1)
    print("%d %d"%(n,m),file=file1,flush=True)
    if m-2*n+1<0:
        ans=0
    else:
        ans=(fact[m-n+1]//fact[m-2*n+1])%mod
    print("%d"%(ans),file=file2,flush=True)
