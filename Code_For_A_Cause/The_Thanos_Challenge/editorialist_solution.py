n=int(input())
for i in range(1,n+1):
    x,y,s=map(str,input().split())
    x,y=int(x),int(y)
    flag=0
    ans=-1
    if(abs(x)+abs(y)==0):
        falg=1
        ans=0
    for j in range(len(s)):
        if(s[j]=='N'):
            y+=1
        elif(s[j]=='S'):
            y-=1
        elif(s[j]=='E'):
            x+=1
        elif(s[j]=='W'):
            x-=1
        if(abs(x)+abs(y) <= j+1):
            flag=1
            ans=j+1
            break
    if(flag==1):
        print(ans)
    else:
        print("IMPOSSIBLE")