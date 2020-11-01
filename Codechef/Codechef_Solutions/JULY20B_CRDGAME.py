def myfun(n):
    s=0
    while n>0:
        s+=n%10
        n//=10
    return s
for test in range(int(input())):
    n=int(input())
    ans1=0
    ans2=0
    for i in range(n):
        a,b=map(int,input().split())
        a1,b1=myfun(a),myfun(b)
        if a1>b1:
            ans1+=1
        elif b1>a1:
            ans2+=1
        else:
            ans1+=1
            ans2+=1
    if ans1==ans2:
        print(2,ans1)
    elif ans1>ans2:
        print(0,ans1)
    else:
        print(1,ans2)