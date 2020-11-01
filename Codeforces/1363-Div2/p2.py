def compute(s1,s2):
    ans=0
    for i in range(len(s1)):
        if s1[i]!=s2[i]:
            ans+=1
    return ans
for test in range(int(input())):
    s=input()
    ans=10**7
    n=len(s)
    s1="0"*n
    s2="1"*n
    s3='0'+'1'*(n-1)
    s4='1'*(n-1)+'0'
    s5='1'+'0'*(n-1)
    s6='0'*(n-1)+'1'
    l=[s1,s2,s3,s4,s5,s6]
    for i in l:
        temp=compute(s,i)
        if temp<ans:
            ans=temp
    for i in range(n):
        s1="0"*(i)+"1"*(n-i)
        temp=compute(s,s1)
        if temp<ans:
            ans=temp
        s1="1"*(i)+"0"*(n-i)
        temp=compute(s,s1)
        if temp<ans:
            ans=temp
    print(ans)