for test in range(int(input())):
    n=int(input())
    ans=0
    temp1=0
    temp2=0
    l=list(map(int,input().split()))
    l.sort(key=lambda x: bin(x)[2:].count("1"))
    ans=int(bin(l[-1])[2:]+bin(l[-2])[2:],2)-int(bin(l[-2])[2:]+bin(l[-1])[2:],2)
    print(abs(ans))