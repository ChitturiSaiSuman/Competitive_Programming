from sys import stdin,stdout
for test in range(int(stdin.readline())):
    n,q=map(int,stdin.readline().split())
    l=list(map(int,stdin.readline().split()))
    ans=0
    for _ in range(q):
        ch,x,y=map(str,stdin.readline().split())
        x,y=int(x),int(y)
        x-=1
        if ch=='U':
            l[x]=y
        else:
            temp=0
            c=0
            for i in range(x,y):
                temp+=pow(-1,c)*l[i]*(c+1)
                c+=1
            ans+=temp
    ans="Case #"+str(test+1)+(": ")+str(ans)+'\n'
    stdout.write(ans)