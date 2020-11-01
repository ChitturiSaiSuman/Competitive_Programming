t=int(input())
while t>0:
    n=int(input())
    l=list(map(int,input().split()))
    flag=True
    last_index=0
    for i in range(n):
        if l[i]==1:
            break
    last_index=i
    for i in range(last_index+1,n):
        if l[i]==1:
            diff=i-last_index
            if diff<6:
                flag=False
                break
            else:
                last_index=i
    print("YES" if flag else "NO")
    t-=1
