def countMax(upright):
    #upright is a list of strings
    x=[]
    y=[]
    for i in upright:
        a,b=map(int,i.split())
        x.append(a)
        y.append(b)
    return (min(x)*min(y))