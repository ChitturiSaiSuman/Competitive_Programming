t=int(input())
while t>0:
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    b=[i for i in l]
    for i in range(n):
        l[i]=(l[i],i)
    l.sort()
    flag=True
    for i in range(n):
        if (l[i][1]-i)%k!=0:
            flag=False
            break
    if not flag:
        flag=True
        s=0
        i=0
        while i<n:
            s=0
            e=l[i][0]
            while i<n and l[i][0]==e:
                if l[i][0]!=b[i]:
                    s+=abs(l[i][1]-i)
                i+=1
            if s%k!=0:
                flag=False
                break
            i+=1
    print("yes" if flag else "no")
    t-=1
