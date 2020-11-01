from itertools import permutations

def getMin(l):
    ans = 0
    for i in range(len(l)-1):
        ans = max(ans,l[i]^l[i+1])
    return ans

def main():
    for i in range(1,11):
        l = list(permutations([j for j in range(1,i+1)]))
        ans = ()
        min_so_far = 10**10
        for j in l:
            temp = getMin(list(j))
            if temp<=min_so_far:
                min_so_far = temp
                ans = j
        print(min_so_far,end=", ")

main()