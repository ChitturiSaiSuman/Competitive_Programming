# cook your dish here
t=int(input())
while t:
    n,k=map(int,input().split())
    l=list(input())
    count=0
    iron=-1
    magnet=-1
    original=l
    cross=-1
    sheets=0
    for i in range(n):
        if(original[i]=="M"):
            magnet=i
        if(original[i]=="I"):
            iron=i
        if(original[i]=="X"):
            cross=i
        if((iron!=-1 or magnet!=-1) and original[i]==":"):
            sheets+=1
        if(iron>=0) and magnet>=0:
            if (cross!=-1) and ((magnet<cross and cross<iron) or (iron<cross and cross<magnet)):
                if(magnet<iron):
                    magnet=-1
                else:
                    iron=-1
                cross=-1
                continue
            else:
                p=k+1-abs(iron-magnet)-sheets
                if(p>0):
                    count+=1
                    sheets=0
                    magnet=-1
                    iron=-1
    print(count)
    t-=1