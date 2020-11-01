t=int(input())
counter=1
while t>0:
    n,k,p=map(int,input().split())
    l=[]
    for _ in range(n):
        temp=list(map(int,input().split()))
        l.append(temp)
    s=[]
    for _ in range(n):
        temp=[0]
        sum=0
        for i in l[_]:
            sum+=i
            temp.append(sum)
        s.append(temp)
    ans=0
    if n==1:
        print("Case #%d:"%(counter),end=" ")
        counter+=1
        print(s[0][p])
    elif n==2:
        ans=0
        for i in range(k+1):
            for j in range(k+1):
                if i+j==p:
                    temp=s[0][i]+s[1][j]
                    if temp>ans:
                        ans=temp
        print("Case #%d:"%(counter),end=" ")
        counter+=1
        print(ans)
    elif n==3:
        ans=0
        for i in range(k+1):
            for j in range(k+1):
                for _ in range(k+1):
                    if i+j+_==p:
                        temp=s[0][i]+s[1][j]+s[2][_]
                        if temp>ans:
                            ans=temp
        print("Case #%d:"%(counter),end=" ")
        counter+=1
        print(ans)
    t-=1
