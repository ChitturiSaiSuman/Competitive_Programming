"""
18
* . * # * * * # * * * # * * * . * .
* . * # * . * # . * . # * * * * * *
* * * # * * * # * * * # * * * * . *
"""
a=[".*.","***","*.*"]
e=["***","***","***"]
I=["***",".*.","***"]
o=["***","*.*","***"]
u=["*.*","*.*","***"]
n=int(input())
line1=''.join(list(map(str,input().split())))
line2=''.join(list(map(str,input().split())))
line3=''.join(list(map(str,input().split())))
ans=""
i=0
while i<n:
    if line1[i]=='#':
        ans+='#'
        i+=1
    elif i+2<n:
        temp=[]
        temp.append(line1[i:i+3])
        temp.append(line2[i:i+3])
        temp.append(line3[i:i+3])
        #print(temp)
        if temp==a:
            ans+='A'
            i+=3
        elif temp==e:
            ans+='E'
            i+=3
        elif temp==I:
            ans+="I"
            i+=3
        elif temp==o:
            ans+='O'
            i+=3
        elif temp==u:
            ans+='U'
            i+=3
        else:
            i+=1
    else:
        i+=1
print(ans)