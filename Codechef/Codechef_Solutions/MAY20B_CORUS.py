from sys import stdin, stdout
t=int(stdin.readline())
while t>0:
    n,q=map(int,stdin.readline().split())
    s=input()
    count=dict()
    for i in s:
        try:
            count[i]+=1
        except:
            count[i]=1
    for _ in range(q):
        c=int(stdin.readline())
        in_queue=0
        for i in count:
            temp=count[i]-c
            if temp<0:
                temp=0
            in_queue+=temp
        stdout.write(str(in_queue)+'\n')
    t-=1