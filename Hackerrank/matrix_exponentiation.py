def dot(a,b):
    mod=10**9+7
    result=[[0,0],[0,0]]
    result[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%mod
    result[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%mod
    result[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%mod
    result[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%mod
    return result
def nth_fibonacci(n):
    initial_matrix=[[1,1],[1,0]]
    result=[[1,0],[0,1]]
    while n>0:
        if n&1==1:
            result=dot(result,initial_matrix)
        initial_matrix = dot(initial_matrix,initial_matrix)
        n//=2
    return result
print(nth_fibonacci(50))