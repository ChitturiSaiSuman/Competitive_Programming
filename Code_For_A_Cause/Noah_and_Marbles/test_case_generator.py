from random import randint
from math import gcd
def lcm(a,b):
    return (a*b)//(gcd(a,b))
def solve(a,n,x):
    ans=0
    for j in range(n):
        ans=gcd(ans,abs(a[j]-x))
    return ans
count_ones=0
input_file = open("input.txt","a")
output_file = open("output.txt","a")
t = 100
for test in range(t):
    n = 1000
    x = randint(-10**8,10**8)
    ans = randint(1,10**4)
    count = dict()
    input_file.write(str(n)+' '+str(x)+'\n')
    l=[]
    diff_list = []
    i = 0
    while i<n:
        multiple = randint(-10**4,10**4) * ans
        try:
            count[multiple]+=1
        except:
            count[multiple]=1
            diff_list.append(multiple)
            i+=1
    for i in range(n):
        coeff= randint(0,1)
        temp_values = [diff_list[i]+x,x-diff_list[i]]
        value = temp_values[coeff]
        l.append(value)
        if i==n-1:
            input_file.write(str(value)+'\n')
        else:
            input_file.write(str(value)+' ')
    answer = solve(l,n,x)
    output_file.write(str(answer)+'\n')