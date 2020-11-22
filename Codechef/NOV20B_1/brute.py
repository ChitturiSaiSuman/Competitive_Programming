# cook your dish here
t=int(input())
while t:
    n,k=map(int,input().split())
    l=list(input())
    count=0
    iron=-1
    magnet=-1
    original=l
    for i in range(len(l)):
        if("I" in l):
            iron=l.index("I")
        if("M" in l):
            magnet=l.index("M")
        if(iron>=0) and magnet>=0:
            if(magnet<iron):
                sub=l[magnet:iron+1]
            else:
                sub=l[iron:magnet+1]
            if("X" in sub):
                if(magnet<iron):
                    l.pop(magnet)
                    magnet=-1
                else:
                    l.pop(iron)
                    iron=-1
                    
            else:
                sheets=sub.count(":")
                p=k+1-abs(iron-magnet)-sheets
                if(p>0):
                    count+=1
                    if(magnet<iron):
                        l.pop(magnet)
                        l.pop(iron-1)
                    else:
                        l.pop(iron)
                        l.pop(magnet-1)
                    magnet=-1
                    iron=-1
    print(count)
    t-=1