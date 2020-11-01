def printer(a):
    print(int(a)+2)
from math import sqrt,gcd
def solve(a,b,c,p,q,r):
    unequal_pairs=0
    if a!=p:
        unequal_pairs+=1
    if b!=q:
        unequal_pairs+=1
    if c!=r:
        unequal_pairs+=1
    if unequal_pairs==0:
        return 0
    elif unequal_pairs==1:
        printer("13")
        return 1
    elif unequal_pairs==2:
        differences=[]
        if a!=p:
            differences.append(a-p)
        if b!=q:
            differences.append(b-q)
        if c!=r:
            differences.append(c-r)
        if differences[0]==differences[1]:
            printer("24")
            return 1
        else:
            quotient=[]
            if a!=p and a!=0 and p%a==0:
                quotient.append(p//a)
            if b!=q and b!=0 and q%b==0:
                quotient.append(q//b)
            if r!=c and c!=0 and r%c==0:
                quotient.append(r//c)
            if len(quotient)==2 and quotient[0]==quotient[1]:
                printer("35")
                return 1
            printer("37")
            return 2
    else:
        difference=[]
        difference.append(p-a)
        difference.append(q-b)
        difference.append(r-c)
        if difference[0]==difference[1] and difference[1]==difference[2]:
            printer("45")
            return 1
        quotient=[]
        if p!=a and a!=0 and p%a==0:
            quotient.append(p//a)
        if q!=b and b!=0 and q%b==0:
            quotient.append(q//b)
        if r!=c and c!=0 and r%c==0:
            quotient.append(r//c)
        if len(quotient)==3:
            if quotient[0]==quotient[1] and quotient[1]==quotient[2]:
                printer("56")
                return 1
            elif quotient[0]==quotient[1] or quotient[1]==quotient[2] or quotient[2]==quotient[0]:
                printer("59")
                return 2
            quotient.sort()
            if quotient[2]==quotient[0]*quotient[1]:
                printer("63")
                return 2
        if len(quotient)==2 and quotient[0]==quotient[1]:
            printer("66")
            return 2
        if difference[0]==difference[1] or difference[1]==difference[2] or difference[2]==difference[0]:
            printer("69")
            return 2
        if c*(p-q)+a*(q-r)==b*(p-r):
            printer("72")
            return 2
        difference.sort()
        if difference[2]==difference[0]+difference[1]:
            printer("76")
            return 2
        g=gcd(p,q)
        g=gcd(g,r)
        if g!=1:
            for i in range(1,int(sqrt(g))+1):
                if g%i==0:
                    temp1=g//i
                    temp2=i
                    x=(p//temp1)-a
                    y=(q//temp1)-b
                    z=(r//temp1)-c
                    if x==y and y==z:
                        printer("85")
                        return 2
                    x=(p//temp2)-a
                    y=(q//temp2)-b
                    z=(r//temp2)-c
                    if x==y and y==z:
                        printer("91")
                        return 2
        if a!=0 and p%a==0:
            x=p//a
            if x!=0 and q%x==0 and r%x==0 and q//x-b==r//x-c:
                printer("96")
                return 2
        if b!=0 and q%b==0:
            x=q//b
            if x!=0 and p%x==0 and r%x==0 and p//x-a==r//x-c:
                printer("101")
                return 2
        if c!=0 and r%c==0:
            x=r//c
            if x!=0 and p%x==0 and q%x==0 and p//x-a==q//x-b:
                printer("106")
                return 2
        d=p-a
        if b!=0 and c!=0 and (q-d)%b==0 and (r-d)%c==0 and (q-d)//b==(r-d)//c:
            printer("110")
            return 2
        d=q-b
        if a!=0 and c!=0 and (p-d)%a==0 and (r-d)%c==0 and (p-d)//a==(r-d)//c:
            printer("114")
            return 2
        d=r-c
        if a!=0 and b!=0 and (p-d)%a==0 and (q-d)%b==0 and (p-d)//a==(q-d)//b:
            printer("118")
            return 2
    printer("120")
    return 3
for test in range(int(input())):
    a,b,c=map(int,input().split())
    p,q,r=map(int,input().split())
    print(solve(a,b,c,p,q,r))