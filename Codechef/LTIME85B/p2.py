from math import sqrt,gcd,log2,log10,floor,ceil,factorial
from sys import stdin,stdout
for test in range(int(input())):
    n=int(input())
    l=sorted(map(int,input().split()))
    count=dict()
    left_list=[]
    right_list=[]
    for i in l:
        try:
            count[i]+=1
        except:
            count[i]=1
    flag=True
    if any([count[i]>2 for i in count]):
        flag=False
    else:
        new_count=dict()
        for i in l:
            try:
                new_count[i]+=1
                right_list.append(i)
            except:
                new_count[i]=1
                left_list.append(i)
        final_list=left_list+right_list[::-1]
        for i in range(n-1):
            if final_list[i]==final_list[i+1]:
                flag=False
                break
    if flag:
        print("YES")
        print(*final_list)
    else:
        print("NO")