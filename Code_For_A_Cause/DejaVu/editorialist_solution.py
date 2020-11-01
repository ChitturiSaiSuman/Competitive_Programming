t=int(input())
for i in range(t):
    n=int(input())
    s1=input()
    w=list(map(str,input().split()))
    s2=w[0]
    x=int(w[1])
    res=0
    flag=1
    p=bin(n).replace("0b","")
    l=len(p)
    for j in range(l):
        if p[j]=='1':
            res+=1
        else:
            if res&1:
                print(s1)
                flag=0
                break
            else:
                res=0
    if flag==1:
        if s1=='Karthik':
            print("Suman")
        else:
            print("Karthik")
    if n%(x+1)==0:
        if s2=='Karthik':
            print("Suman")
        else:
            print("Karthik")
    else:
        print(s2)