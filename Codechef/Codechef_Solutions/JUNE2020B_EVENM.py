# Python3 program to print a n x n spiral matrix 
# in clockwise direction using O(1) space 

# Prints spiral matrix of size n x n 
# containing numbers from 1 to n x n 
def printSpiral(n) : 
	
	for i in range(0, n) : 
		for j in range(0, n) : 
			
			# Finds minimum of four inputs 
			x = min(min(i, j), min(n - 1 - i, n - 1 - j)) 
			
			# For upper right half 
			if (i <= j) : 
				print((n - 2 * x) * (n - 2 * x) -
					(i - x)- (j - x), end = " ") 

			# For lower left half 
			else : 
				print(((n - 2 * x - 2) *
					(n - 2 * x - 2) +
					(i - x) + (j - x)), end = " ") 
		print() 
		
# Driver code 
for test in range(int(input())):
    printSpiral(int(input()))