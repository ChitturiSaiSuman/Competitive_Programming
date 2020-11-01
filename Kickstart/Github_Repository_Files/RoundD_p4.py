from sys import stdin,stdout
for test in range(int(input())):
    print("Case #%d: "%(test+1),end="")
    ans = []
    n,q = map(int,stdin.readline().split())
    l = list(map(int,stdin.readline().split()))
    for j in range(q):
        ent,last_room = map(int,stdin.readline().split())
        list1 = l[:ent-1]
        list2 = l[ent-1:]
        ind1 = ent+1
        ind2 = ent-1
        room_unlocked=[ent]
        for i in range(last_room):
            if len(list1)>0 and len(list2)>0:
                if list1[-1]>list2[0]:
                    list2.pop(0)
                    room_unlocked.append(ind1)
                    ind1+=1
                else:
                    list1.pop()
                    room_unlocked.append(ind2)
                    ind2-=1
            elif len(list1)>0:
                list1.pop()
                room_unlocked.append(ind2)
                ind2-=1
            elif len(list2)>0:
                list2.pop(0)
                room_unlocked.append(ind1)
                ind1+=1
        ans.append(room_unlocked[last_room-1])
    print(*ans)