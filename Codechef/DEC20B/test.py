from math import log2,log10
def getNext(l,n,i):
    seq = []
    b = bin(i)[2:]
    b = (n - len(b))*"0" + b
    for i in range(n):
        if b[i]=='0':
            seq.append(l[i])
        else:
            seq.append(-l[i])
    return seq,b

def check(l,n,k):
    count = 0
    for i in range(2**n):
        temp = []
        b = bin(i)[2:]
        if b.count("1") != k:
            continue
        b = "0"*(n-len(b)) + b
        for bit in range(n):
            if b[bit] == '1':
                temp.append(l[bit])
        if sum(temp)>0:
            count += 1
    return count == 1

def main():
    n,k = map(int,input().split())
    l = [i for i in range(1,n+1)]
    vals = []
    for i in range(2**n):
        temp,b = getNext(l,n,i)
        if check(temp,n,k):
            vals.append(temp)
    vals.sort()
    for i in vals:
        print(i)
            

for test in range(int(input())):
    main()

# print(log10(875**10))