def matmul(a,b,res,moD = 10**30):
    m = len(a)
    n = len(a[0])
    p = len(b[0])
    result = [[0 for i in range(p)] for j in range(m)]
    for i in range(m):
        for j in range(p):
            result[i][j] = 0
            for k in range(n):
                result[i][j] += a[i][k] * b[k][j]
            result[i][j] %= moD
    for i in range(m):
        for j in range(p):
            res[i][j] = result[i][j]
    
def nthFibonacci(n):
    base = [[1,1],[1,0]]
    result = [[1,0],[0,1]]
    while n>0:
        if n&1 == 1:
            matmul(base,result,result,10**9+7)
        matmul(base,base,base,10**9+7)
        n >>= 1
    return result[0][1]

def main():
    print(nthFibonacci(10**9+1))

main()