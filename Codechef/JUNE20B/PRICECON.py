for _ in range(int(input())):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    s=sum(l)
    l=[i if i<k else k for i in l]
    print(s-sum(l))