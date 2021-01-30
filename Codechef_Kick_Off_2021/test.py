"""
Author: Chitturi Sai Suman
Created: 2021-01-30 10:59:09
"""
def lead_game(c):
    p1=0
    p2=0
    m=0
    for i in range(c):
        a,b=map(int,input().split())
        p1+=a
        p2+=b
        l=abs(p1-p2)
        if(l>m):
            m=l
            if p1>p2 :
                r=1
            else:
                r=2
    print(r,m)


t=int(input())
lead_game(t)