from math import gcd,factorial,sqrt,ceil,floor,log2,log10
for test in range(int(input())):
    l=list(map(int,input().split()))
    p=l[-1]
    l.pop()
    for i in range(5):
        l[i]=l[i]*p
    s=sum(l)
    if s<=120:
        print("No")
    else:
        print("Yes")