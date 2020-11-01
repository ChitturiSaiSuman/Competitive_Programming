"""
2

2 4

6 2
"""
# Program to find minimum 
# number of platforms 
# required on a railway 
# station 

# Returns minimum number 
# of platforms reqquired 
def findPlatform(arr, dep, n): 

	# Sort arrival and 
	# departure arrays 
	arr.sort() 
	dep.sort() 

	# plat_needed indicates 
	# number of platforms 
	# needed at a time 
	plat_needed = 1
	result = 1
	i = 1
	j = 0

	# Similar to merge in 
	# merge sort to process 
	# all events in sorted order 
	while (i < n and j < n): 
	
		# If next event in sorted 
		# order is arrival, 
		# increment count of 
		# platforms needed 
		if (arr[i] <= dep[j]): 
		
			plat_needed+= 1
			i+= 1
		

		# Else decrement count 
		# of platforms needed 
		elif (arr[i] > dep[j]): 
		
			plat_needed-= 1
			j+= 1

		# Update result if needed 
		if (plat_needed > result): 
			result = plat_needed 
		
	return result 

# driver code 
n=int(input())
arr=[]
dep=[]
for i in range(n):
    a,b=map(int,input().split())
    b=a+b
    arr.append(a)
    dep.append(b)

print(findPlatform(arr, dep, n))
