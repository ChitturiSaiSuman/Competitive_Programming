from sys import stdin,stdout
for test in range(int(stdin.readline())):
    n=int(stdin.readline())
    countx=dict()
    county=dict()
    for i in range(4*n-1):
        x,y=map(int,stdin.readline().split())
        try:
            countx[x]+=1
        except:
            countx[x]=1
        try:
            county[y]+=1
        except:
            county[y]=1
    x=y=0
    for i in countx:
        if countx[i]%2==1:
            x=i
            break
    for i in county:
        if county[i]%2==1:
            y=i
            break
    ans=str(x)+" "+str(y)
    stdout.write(ans+'\n')