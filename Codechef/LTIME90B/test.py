from fractions import Fraction
l = []
for n in range(1,100):
    ans = 0
    for i in range(1,n+1):
        for j in range(i+1,n+1):
            f = Fraction(i*(j+1),(i+1)*j)
            if f.numerator == f.denominator - 1:
                ans += 1
    l.append(ans)
print(l)