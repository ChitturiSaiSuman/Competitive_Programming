neg=0
pos=0
for test in range(int(input())):
    s,n,k,r=map(int,input().split())
    required=(k*(pow(r,n)-1))//(r-1)
    if required<=s:
        print("POSSIBLE",s-required)
        pos+=s-required
    else:
        print("IMPOSSIBLE",required-s)
        neg+=required-s
if pos-neg>=0:
    print("POSSIBLE")
