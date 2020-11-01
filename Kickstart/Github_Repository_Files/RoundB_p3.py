limit=10**9
case=1
t=int(input())
while t>0:
    s=input()
    stack=[]
    for i in range(len(s)):
        if s[i]==')':
            temp=""
            while stack[-1]!='(':
                temp+=stack.pop()
            stack.pop()
            stack.append(temp*int(stack.pop()))
        else:
            stack.append(s[i])
    s=''.join(stack)
    pair=[1,1]
    for i in s:
        if i=="S":
            pair[1]=(pair[1]+1)
            if pair[1]==limit+1:
                pair[1]=1
        elif i=="E":
            pair[0]=(pair[0]+1)
            if pair[0]==limit+1:
                pair[0]=1
        elif i=="W":
            pair[0]=pair[0]-1
            if pair[0]==0:
                pair[0]=limit
        elif i=="N":
            pair[1]-=1
            if pair[1]==0:
                pair[1]=limit
    print("Case #%d: %d %d"%(case,pair[0],pair[1]))
    case+=1
    t-=1
