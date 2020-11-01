from sys import stdin,stdout
for test in range(int(stdin.readline())):
    n=int(stdin.readline())
    l1=list(map(int,stdin.readline().split()))
    l2=list(map(int,stdin.readline().split()))
    count1=dict()
    count2=dict()
    total=dict()
    for i in l1:
        try:
            count1[i]+=1
        except:
            count1[i]=1
        try:
            total[i]+=1
        except:
            total[i]=1
    for i in l2:
        try:
            count2[i]+=1
        except:
            count2[i]=1
        try:
            total[i]+=1
        except:
            total[i]=1
    if any([total[i]%2==1 for i in total]):
        stdout.write("-1"+'\n')
    else:
        flag=True
        for i in l1:
            try:
                if count1[i]!=count2[i]:
                    flag=False
                    break
                if not flag:
                    break
            except:
                flag=False
                break
        if flag:
            stdout.write("0"+'\n')
        else:
            extra1=[]
            extra2=[]
            for i in count1:
                try:
                    if count2[i]<count1[i]:
                        extra1.append((i,count1[i]-count2[i]))
                except:
                    extra1.append((i,count1[i]))
            for i in count2:
                try:
                    if count1[i]<count1[i]:
                        extra2.append((i,count2[i]-count1[i]))
                except:
                    extra2.append((i,count2[i]))
            min1=min(l1)
            min2=min(l2)
            extra1.sort()
            extra2.sort()
            answer=0
            for pair in extra1:
                pass