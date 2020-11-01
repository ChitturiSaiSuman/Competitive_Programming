from sys import stdin,stdout
for test in range(int(stdin.readline())):
    n,m=map(int,stdin.readline().split())
    a=list(map(int,stdin.readline().split()))
    count=dict()
    for i in a:
        try:
            count[i]+=1
        except:
            count[i]=1
    try:
        if all([count[i]>0 for i in range(1,m)]):
            if m in a:
                ans=n-count[m]
            else:
                ans=n
            print(ans)
    except:
        print(-1)