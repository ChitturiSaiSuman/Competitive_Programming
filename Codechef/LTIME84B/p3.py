import bisect
for test in range(int(input())):
    n=int(input())
    s1=input()
    s2=input()
    if s1==s2:
        print(0)
        continue
    flag=True
    for i in range(n):
        if ord(s1[i])<ord(s2[i]):
            flag=False
            break
    set1=set()
    set2=set()
    for i in range(n):
        set1.add(s1[i])
        set2.add(s2[i])
    set1,set2=list(set1),list(set2)
    for i in set2:
        if i not in set1:
            flag=False
            break
    if not flag:
        print(-1)
        continue
    ans=[]
    s1=[i for i in s1]
    s2=[i for i in s2]
    for i in range(122,96,-1):
        ch=chr(i)
        temp=[]
        flag=False
        for j in range(n):
            if s2[j]==ch:
                if s1[j]!=ch:
                    flag=True
                temp.append(j)
        for j in temp:
            s1[j]=ch
        if flag:
            ans.append(temp)
    if s1!=s2:
        print(-1)
        continue
    print(len(ans))
    for i in ans:
        print(len(i),*i)