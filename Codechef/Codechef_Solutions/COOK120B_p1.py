#A part of this code is taken from https://www.geeksforgeeks.org/count-distinct-bitwise-or-of-all-subarrays/
# Python implementation of the above approach 

# function to return count of distinct bitwise OR 
def subarrayBitwiseOR(A): 

	# res contains distinct values 
	res = set() 

	pre = {0} 

	for x in A: 
		pre = {x | y for y in pre} | {x} 
		res |= pre 

	return len(res) 


# Driver program 
for test in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    ans=(n*(n+1))//2
    if subarrayBitwiseOR(l)!=ans:
        print("NO")
    else:
        print("YES")