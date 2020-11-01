from bisect import bisect_left,bisect_right,bisect
for test in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    stacks = [l[0]]
    length = 1
    for i in range(1,n):
        element = l[i]
        ind = bisect_right(stacks,element,0,length)
        if ind==length:
            stacks.append(element)
            length+=1
        elif ind>=0 and ind<length:
            stacks[ind] = element
        # print(stacks,ind,element)
    print(len(stacks),*stacks)