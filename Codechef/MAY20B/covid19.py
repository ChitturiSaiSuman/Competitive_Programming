t=int(input())
while t>0:
    n=int(input())
    min_ans=n
    max_ans=0
    l=list(map(int,input().split()))
    for i in range(n):
        infected=[False for _ in range(n)]
        infected[i]=True
        j=i+1
        while j<n and l[j-1]+2>=l[j]:
            infected[j]=True
            j+=1
        j=i-1
        while j>=0 and l[j]+2>=l[j+1]:
            infected[j]=True
            j-=1
        current_infected=infected.count(True)
        if current_infected<min_ans:
            min_ans=current_infected
        if current_infected>max_ans:
            max_ans=current_infected
    print(min_ans,max_ans)
    t-=1