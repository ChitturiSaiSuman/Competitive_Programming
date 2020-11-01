for test in range(int(input())):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    even=0
    odd=0
    for i in l:
        if i%2==0:
            even+=1
        else:
            odd+=1
    if k==n:
        print("Yes" if odd%2==1 else "No")
    else:
        if odd==0:
            print("No")
        else:
            if k%2==0:
                flag=False
                for i in range(1,k,2):
                    v1=i
                    v2=k-i
                    if v1<=odd and v2<=even:
                        flag=True
                        break
                print("Yes" if flag else "No")
            else:
                flag=False
                for i in range(1,k+1,2):
                    v1=i
                    v2=k-i
                    if v1<=odd and v2<=even:
                        flag=True
                        break
                print("Yes" if flag else "No")