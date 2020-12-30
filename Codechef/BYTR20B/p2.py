# A part of this code is taken from https://www.geeksforgeeks.org/represent-n-as-the-sum-of-exactly-k-powers-of-two-set-2/
# Python 3 implementation of the above approach 

# Function to print k numbers which are 
# powers of two and whose sum is equal to n 
def FindAllElements(n, k): 
	
	# Initialising the sum with k 
	sum = k 

	# Initialising an array A with k elements 
	# and filling all elements with 1 
	A = [1 for i in range(k)] 
	i = k - 1
	while(i >= 0): 
		
		# Iterating A[] from k-1 to 0 
		while (sum + A[i] <= n): 
			
			# Update sum and A[i] till 
			# sum + A[i] is less than equal to n 
			sum += A[i] 
			A[i] *= 2
		i -= 1
	
	# Impossible to find the combination 
	if (sum != n): 
		return [-1] 

	# Possible solution is stored in A[] 
	else: 
		ans = []
        for i in range(0, k, 1):
			ans.append(A[i])
        return ans
            # print(A[i], end = ' ') 
# Driver code 
if __name__ == '__main__': 
	n = 12
	k = 6

	FindAllElements(n, k) 

# This code is contributed by 
# Surendra_Gangwar 

for test in range(int(input())):
    n,k = map(int,input().split())
    ans = FindAllElements(k,n)
    print(*ans)