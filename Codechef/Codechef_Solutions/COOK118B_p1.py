from math import gcd,sqrt,ceil,floor,log,log2
t=int(input())
while t>0:
    n=int(input())
    l=list(map(int,input().split()))
    flag=[False for i in range(10**3+4)]
    count=dict()
    i=0
    ans=True
    while i<n:
        temp=l[i]
        if not flag[temp]:
            flag[temp]=True
            while i<n and l[i]==temp:
                i+=1
                try:
                    count[temp]+=1
                except:
                    count[temp]=1
            i-=1
        else:
            ans=False
            break
        i+=1
    if not ans:
        print("NO")
        t-=1
        continue
    l=[count[i] for i in count]
    s=set(l)
    if len(s)!=len(l):
        print("NO")
    else:
        print("YES")
    t-=1