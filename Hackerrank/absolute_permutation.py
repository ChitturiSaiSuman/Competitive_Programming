from itertools import permutations
def is_valid(l,k):
    return all([abs(i+1-l[i])==k for i in range(len(l))])

def main():
    for n in range(1,11):
        l = list(permutations([i for i in range(1,n+1)]))
        for perm in l:
            for k in range(0,n):
                if is_valid(perm,k):
                    print(n,k,perm)

main()