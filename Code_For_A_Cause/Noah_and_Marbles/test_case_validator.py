import math
def solve(a,n,x):
    ans=0
    for j in range(n):
        ans=math.gcd(ans,abs(a[j]-x))
    return ans
input_file = open("input.txt","r")
output_file = open("output.txt","r")
t = int(input_file.readline())
for test in range(t):
    n,x = map(int,input_file.readline().split())
    if n<1 or n>1000:
        print("N is not within limits")
    if x<-10**9 or x>10**9:
        print("X is not within limits")
    l = list(map(int,input_file.readline().split()))
    if len(l)!=n:
        print("Elements on single line")
    if any([i>10**9 or i<-10**9 for i in l]):
        print("Elements not within limits")
    actual_ans = solve(l,n,x)
    test_ans = int(output_file.readline())
    if actual_ans!=test_ans:
        print("Test failed")
input_file.close()
output_file.close()