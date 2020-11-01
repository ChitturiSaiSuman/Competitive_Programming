t=int(input())
while t>0:
    n,s=map(int,input().split())
    p=list(map(int,input().split()))
    l1=[]
    l2=[]
    b=list(map(int,input().split()))
    for i in range(n):
        if b[i]==1:
            l1.append(p[i])
        else:
            l2.append(p[i])
    try:
        if min(l1)+min(l2)+s<=100:
            print("yes")
        else:
            print("no")
    except:
        print("no")
    t-=1
