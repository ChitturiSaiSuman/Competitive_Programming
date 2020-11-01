for _ in range(int(input())):
    n,k=map(int,input().split())
    a1=n*n
    a2=n*(n+2)
    if n==0:
        a2=2
        ans=k*(k-1)
        print(ans)
        continue
    d=(n+1)*2
    if k%2==1:
        k=(k+1)//2
        k-=1
        ans=a1+(k*(2*d+(k-1)*2))//2
    else:
        k//=2
        k-=1
        ans=a2+(k*(2*d+(k-1)*2))//2
    print(ans)