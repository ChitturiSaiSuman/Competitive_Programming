from math import gcd,factorial,sqrt,ceil,floor,log2,log10
for test in range(int(input())):
    n=int(input())
    ans=0
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    sum1=0
    sum2=0
    for i in range(n):
        sum1+=l1[i]
        sum2+=l2[i]
        if sum1==sum2 and l1[i]==l2[i]:
            ans+=l1[i]
    print(ans)