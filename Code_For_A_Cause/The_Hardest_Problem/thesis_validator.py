from fractions import Fraction
size=10**5
phi=[i for i in range(size)]
for i in range(2,size):
    if phi[i]==i:
        phi[i]=i-1
        for j in range(2*i,size,i):
            phi[j]=(phi[j]//i)*(i-1)
ratio=[Fraction(phi[i],i) for i in range(1,size)]
for i in range(2,100):
    m=max(ratio[1:i])
    print(m,ratio[1:i].count(m))