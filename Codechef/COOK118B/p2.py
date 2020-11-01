t=int(input())
while t>0:
    s=input()
    ans=0
    for i in range(2,len(s),2):
        temp1=s[:i]
        temp2=s[i:]
        l1=len(temp1)
        l2=len(temp2)
        if temp1[:l1//2]==temp1[l1//2:] and temp2[:l2//2]==temp2[l2//2:]:
            ans+=1
    print(ans)
    t-=1