n=int(input())
s1=input()
s2=input()
m=0
r=0
for i in s2:
    if i=='m':
        m+=1
    else:
        r+=1
match=0
for i in s1:
    if i=='m' and m>0:
        m-=1
        match+=1
    elif i=='r' and r>0:
        r-=1
        match+=1
    else:
        break
print(n-match)