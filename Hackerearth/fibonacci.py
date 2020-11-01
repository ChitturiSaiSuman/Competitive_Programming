def matmul(a,b,result,mod=10**9+7):
    res = [[0,0],[0,0]]
    res[0][0] = a[0][0]*b[0][0]+a[0][1]*b[1][0]
    res[0][1] = a[0][0]*b[0][1]+a[0][1]*b[1][1]
    res[1][0] = a[1][0]*b[0][0]+a[1][1]*b[1][0]
    res[1][1] = a[1][0]*b[1][0]+a[1][1]*b[1][1]
    for i in range(2):
        for j in range(2):
            result[i][j]=res[i][j]%(mod-1)

def nth_fibonacci(n):
    if n<2:
        return n
    base = [[1,1],[1,0]]
    result = [[1,0],[0,1]]
    while n>0:
        if n&1==1:
            matmul(base,result,result)
        matmul(base,base,base)
        n//=2
    return result[0][1]

def nth_term(a,b,n,mod=10**9+7):
    if n==0:
        return a
    elif n==1:
        return b
    return (pow(a,nth_fibonacci(n-1),mod)*pow(b,nth_fibonacci(n),mod))%mod


# def solve(a,b,n,mod=10**9+7):
#     if n==0:
#         return a
#     else:
#         term = (pow(a,nth_fibonacci(n-1),mod) * pow(b,nth_fibonacci(n),mod))%mod
#         return term
def brute(a,b,n):
    fib = [a,b]
    for i in range(n):
        fib.append((fib[-1]*fib[-2])%(10**9+7))
    return fib[n]
    
for test in range(int(input())):
    a,b,n = map(int,input().split())
    ans1 = nth_term(a,b,n)
    ans2 = brute(a,b,n)
    if ans1!=ans2:
        print("Error")