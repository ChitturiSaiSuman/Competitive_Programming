from math import log2
t=int(input())
while t>0:
    n=int(input())
    if int(log2(n))==log2(n):
        print(-1)
    else:
        ans=(n-1)//2
        i=1
        coeff=(ans)//2
        while pow(2,i)<n:
            ans+=pow(2,i)*(coeff+1)
            i+=1
            coeff=(coeff)//2
        print(ans)
    t-=1
