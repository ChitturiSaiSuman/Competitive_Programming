def find(a,b):
    ans=0
    while a>0 and b>0:
        if a>b:
            a-=b
        else:
            b-=a
        ans+=1
    return ans
p=int(input())
q=int(input())
r=int(input())
s=int(input())
ans=0
for i in range(p,q+1):
    for j in range(r,s+1):
        ans+=find(i,j)
print(ans)