"""Sieve for prime generation, sum of primes, count of primes
def sieve(size):
    prime=[0]*size
    prime[2]=1
    for i in range(3,size,2):
        prime[i]=1
    for i in range(3,int(sqrt(size))+1,2):
        if prime[i]==1:
            for j in range(i*i,size,i):
                prime[j]=0
    count=[0]*size
    sum=[0]*size
    for i in range(1,size):
        count[i]=count[i-1]+prime[i]
        sum[i]=sum[i-1]+prime[i]*i
    obj=[(prime[i],count[i],sum[i]) for i in range(size)]
    return obj
"""
""" Maximum Subsequence Sum
def max_subsequence_sum(a,n):
    this_sum=0
    max_sum=0
    for i in range(n):
        this_sum+=a[i]
        if this_sum>max:
            max_sum=this_sum
        elif this_sum<0:
            this_sum=0
    return max_sum
"""
""" Check whether prime or not
def is_prime(n):
    if n==0 or n==1:
        return False
    elif n==2 or n==3:
        return True
    elif n%2==0 or n%3==0:
        return False
    for i in range(5,int(sqrt(n))+1,6):
        if n%i==0 or n%(i+2)==0:
            return False
    return True
"""
""" Binary search
def binary_search(a,lb,ub,key):
    while lb<=ub:
        mid=(lb+ub)//2
        if a[mid]==key:
            return mid
        elif a[mid]<key:
            lb=mid+1
        else:
            ub=mid-1
    return -1
"""
""" nCr mod p using fermat's principle
fact=[1]*size
mod=10**9+7
for i in range(1,size):
    fact[i]=(fact[i-1]*i)%mod
def ncr_mod_p(n,r,p):
    global fact
    if r==0:
        return 1
    return ((fact[n]*pow(fact[r],p-2,p))%p * pow(fact[n-r],p-2,p))%p
"""
""" LCM of two Integers
lcm=lambda x,y: ((x*y)//gcd(x,y))
"""
""" Factorisation in sqrt(n)
def factor(n):
    ans=1
    c=0
    while n%2==0:
        n//=2
        c+=1
    ans*=c+1
    c=0
    while n%3==0:
        n//=3
        c+=1
    ans*=c+1
    for i in range(3,int(sqrt(n))+1,2):
        c=0
        while n%i==0:
            n//=i
            c+=1
        ans*=c+1
        c=0
        while n%(i+2)==0:
            n//=i
            c+=1
        ans*=c+1
    if n>2:
        ans*=2
    return ans
"""
""" Sieve in O(log n) using spf
size=10**5
spf=[i for i in range(size)]
for i in range(2,size,2):
    spf[i]=2
for i in range(3,int(sqrt(size)),2):
    if spf[i]==i:
        for j in range(i*i,size,i):
            if spf[j]==j:
                spf[j]=i
def factorise(n):
    global spf
    ans=1
    while n>1:
        c=0
        k=spf[n]
        while k==spf[n]:
            n//=spf[n]
            c+=1
        ans*=c+1
    return ans
"""
""" Euler's Totient Function
phi=[i for i in range(size)]
for i in range(2,size):
    if phi[i]==i:
        for j in range(i,size,i):
            phi[j]-=phi[j]//i
"""
""" Nth Fibonacci in O(log(n))
def dot(a,b,res):
    result=[[0,0],[0,0]]
    mod=10**9+7
    result[0][0]=((a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0])%mod)%mod
    result[0][1]=((a[0][0]*b[0][1])%mod+(a[0][1]*b[1][1])%mod)%mod
    result[1][0]=((a[1][0]*b[0][0])%mod+(a[1][1]*b[1][0])%mod)%mod
    result[1][1]=((a[1][0]*b[0][1])%mod+(a[1][1]*b[1][1])%mod)%mod
    res[0][0]=result[0][0]
    res[0][1]=result[0][1]
    res[1][0]=result[1][0]
    res[1][1]=result[1][1]
def nth_fibonacci(n):
    result=[[1,0],[0,1]]
    base=[[1,1],[1,0]]
    if n<2:
        return n
    while n>0:
        if n&1==1:
            dot(base,result,result)
        dot(base,base,base)
        n//=2
    return result[0][1]
"""
""" Count Set Bits
count_set_bits=lambda x: bin(x).count("1")
"""