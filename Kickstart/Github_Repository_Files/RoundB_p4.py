import math
t=int(input())
case_count=1
def solve():
    n=int(input())
    
while t>0:
    n=int(input())
    print("Case #%d: ",case_count,end="")
    solve()
    case_count+=1
    t-=1
    
