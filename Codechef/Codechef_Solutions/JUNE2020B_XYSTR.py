for test in range(int(input())):
    s=input()
    ans=0
    stack=[]
    for i in range(len(s)):
        if stack==[]:
            stack.append(s[i])
        elif stack[-1]!=s[i]:
            ans+=1
            stack.pop()
    print(ans)