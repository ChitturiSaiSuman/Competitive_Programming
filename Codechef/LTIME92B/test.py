# Python3 program for the above approach

# Function to map
# numbers using coordinate
# compression
def coordinateCompression(arr, n):

	# Set will store
	# all unique numbers
	s = dict()
	for i in range(n):
		s[arr[i]] = 1

	# Map will store
	# the new elements
	index = 0
	mp = dict()

	for itr in sorted(s):
		
		# For every new number in the set,
		index += 1
		
		# Increment the index of the
		# current number and store it
		# in a hashmap. Here index
		# for every element is the
		# new value with with the
		# current element is replaced
		mp[itr] = index
	for i in range(n):
		
		# now change the current element
		# to range 1 to N.
		arr[i] = mp[arr[i]]

# Function to calculate
# length of maximum
# increasing sequence till
# i'th index
def query(BIT, index, n):

	ans = 0
	while (index > 0):
		ans = max(ans, BIT[index])
		
		# Go to parent node
		index -= index & (-index)
	return ans

# Function for updating
# BIT array for maximum
# increasing sequence till
# i'th index
def update(BIT, index, n):

	# If 4 is inserted in BIT,
	# check for maximum length
	# subsequence till element 3.
	# Let this subsequence length be x.
	# If x + 1 is greater than
	# the current element in BIT,
	# update the BIT array
	x = query(BIT, index - 1, n)
	value = x + 1
	while (index <= n):

		# Store maximum length subsequence length till index
		# Here index is the
		# coordinate compressed element
		BIT[index] = max(BIT[index], value)

		# Go to child node and update that node
		index += index & (-index)

# Function to calculate
# maximum Longest Increasing
# Sequene length
def findLISLength(arr, n):

	coordinateCompression(arr, n)
	BIT = [0]*(n + 1)

	for i in range(n):
		
		# Add elements
		# from left to right
		# in BIT
		update(BIT, arr[i], n)

	ans = query(BIT, n, n)
	return ans

# Driver code
arr=[6, 5, 1, 3, 2, 4, 8, 7]
n = len(arr)
ans = findLISLength(arr, n)

print(ans)

# This code is contributed mohit kumar 29
