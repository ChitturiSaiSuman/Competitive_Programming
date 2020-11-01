from math import sqrt
size=10**4
prime=[True]*size
prime[0]=prime[1]=False
for i in range(4,size,2):
    prime[i]=False
for i in range(3,int(sqrt(size))+1,2):
    if prime[i]:
        for j in range(i*i,size,i):
            prime[j]=False
a,b=map(int,input().split())
first_list=[]
for i in range(a,b+1):
    if prime[i]:
        first_list.append(i)
new_list=set()
n=len(first_list)
for i in range(n):
    for j in range(n):
        if i!=j:
            temp=int(str(first_list[i])+str(first_list[j]))
            new_list.add(temp)
new_list=list(new_list)
final_list=[]
for i in new_list:
    if prime[i]:
        final_list.append(i)
n=len(final_list)
a=min(final_list)
b=max(final_list)
n-=2
fib=[a,b]
for i in range(n):
    fib.append(fib[-1]+fib[-2])
print(fib[-1]%(10**18+9))