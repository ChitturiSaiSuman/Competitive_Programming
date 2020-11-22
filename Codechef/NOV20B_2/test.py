from collections import defaultdict
mod = 998244353
inverse = lambda x: pow(x,mod-2,mod)
mul = lambda x,y: (x*y)%mod
a,b,c,d = 5,8,14,12
total = (a+1)
count = defaultdict(int)
for i in range(a+1):
    for j in range(b+1):
        for k in range(c+1):
            for l in range(d+1):
                count[min(i,a-i,j,b-j,k,c-k,l,d-l)]+=1
print(count)
num = 0
for i in count:
    num += i*count[i]
print(num,total)
print(mul(num,inverse(total)))
# print(mul(24,inverse(120)))