def score(n):
    lsb=10
    msb=-1
    temp=n
    while temp>0:
        lsb=min(lsb,temp%10)
        temp//=10
    temp=n
    while temp>0:
        msb=max(msb,temp%10)
        temp//=10
    ans=msb*11+lsb*7
    d1=ans%10
    ans//=10
    d2=ans%10
    ans=d2*10+d1
    return ans
def msb(n):
    n//=10
    return n
n=int(input())
a=list(map(int,input().split()))
b=[score(a[i]) for i in range(n)]
ans=0
for m in range(10):
    count1=0
    for i in range(0,n,2):
        if msb(b[i])==m:
            count1+=1
    count2=0
    for i in range(1,n,2):
        if msb(b[i])==m:
            count2+=1
    if count1>2 or count2>2:
        ans+=2
    elif count1==2 or count2==2:
        ans+=1
print(ans)