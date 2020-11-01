for test in range(int(input())):
    print("Case #%d: "%(test+1),end="")
    n,a,b,c=map(int,input().split())
    if n==1:
        if a>1 or b>1 or c>1:
            print("IMPOSSIBLE")
        else:
            print(1)
        continue
    elif n==2:
        if c==2 and a==2 and b==2:
            print(1,1)
        elif a==2 and b==1 and c==1:
            print(1,2)
        elif b==2 and a==1 and c==1:
            print(2,1)
        else:
            print("IMPOSSIBLE")
        continue
    # elif a==c and b==c and a<n:
    #     print("IMPOSSIBLE")
    #     continue
    first = [n-1 for i in range(1,a+1-c)]
    last=[n-1 for i in range(1,b+1-c)]
    mid=[n for i in range(c)]
    if a==c and b==c:
        answer=mid[:1]+[1 for i in range(n-c)]+mid[1:]
    elif a==c:
        answer=mid+[1 for i in range(n-b)]+last
    elif b==c:
        answer=first+[1 for i in range(n-a)]+mid+last
    else:
        answer=first+mid+last
    if len(answer)>n:
        print("IMPOSSIBLE")
    else:
        if len(answer)<n:
            answer=first+mid[:1]+[1 for i in range(n-(len(first)+len(last)+len(mid)))]+mid[1:]+last
        print(*answer)