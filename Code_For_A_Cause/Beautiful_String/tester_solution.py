from sys import stdin,stdout
def solve(s,length,a,b):
    prefix=[0]*length
    prefix[0]=int(s[0])
    for i in range(1,length):
        prefix[i]=prefix[i-1]+int(s[i])
    total_ones = s.count("1")
    total_zeroes = length - total_ones
    answer = min (total_ones*b, total_zeroes*a)
    for i in range(length):
        ones_on_left = prefix[i]
        zeroes_on_left = (i+1)-ones_on_left
        ones_on_right = total_ones - ones_on_left
        zeroes_on_right = total_zeroes - zeroes_on_left
        temp_cost = zeroes_on_left*a + ones_on_right*b
        answer = min(answer,temp_cost)
        temp_cost = ones_on_left*b + zeroes_on_right * a
        answer = min(answer, temp_cost)
    print(answer)
l=list(map(str,stdin.read().split("\n")))
l.pop()
t=int(l[0])
for i in range(1,len(l),2):
    n,a,b=map(int,l[i].split())
    s=l[i+1]
    solve(s,n,a,b)