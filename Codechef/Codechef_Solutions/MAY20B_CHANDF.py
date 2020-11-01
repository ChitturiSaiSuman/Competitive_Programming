from math import log2
size=8
for test in range(int(input())):
    a,b,l,r=map(int,input().split())
    result = a|b
    if result>r:
        power=int(log2(result))
        while result>r:
            if result & pow(2,power)==pow(2,power):
                result-=pow(2,power)
            power-=1
    if result<l:
        result=result|l
    print(result)