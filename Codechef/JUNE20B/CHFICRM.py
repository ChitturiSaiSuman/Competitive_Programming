for test in range(int(input())):
    n=int(input())
    fives=0
    tens=0
    fifteens=0
    flag=True
    l=list(map(int,input().split()))
    for i in l:
        if i==5:
            fives+=1
        elif i==10:
            if fives>0:
                fives-=1
                tens+=1
            else:
                flag=False
                break
        elif i==15:
            if tens>0:
                tens-=1
                fifteens+=1
            elif fives>1:
                fives-=2
                fifteens+=1
            else:
                flag=False
                break
    print("YES" if flag else "NO")