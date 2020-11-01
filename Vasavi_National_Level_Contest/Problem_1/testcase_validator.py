from math import sqrt
from random import randint
size = 10**6+5
prime=[0]*size
prime[2]=1
for i in range(3,size,2):
    prime[i]=1
for i in range(3,int(sqrt(size))+1,2):
    if prime[i]==1:
        for j in range(i*i,size,i):
            prime[j]=0
count=[0]*size
for i in range(1,size):
    count[i]=count[i-1]+prime[i]
def solve(n):
    if n==1 or n==0:
        return 0
    global count
    return pow(2,count[n]-1,10**9+7)
input_file = open("input.txt","r")
output_file = open("output.txt","r")
input_set= input_file.readlines()
output_set= output_file.readlines()
output_set=[int(i) for i in output_set]
input_set =[int(i) for i in input_set]
input_file.close()
output_file.close()
input_set.pop(0)
for i in range(len(input_set)):
    if input_set[i]<1 or input_set[i]>10**6:
        print(1/0)
    if solve(input_set[i])!=(output_set[i]):
        print(input_set[i],output_set[i])
