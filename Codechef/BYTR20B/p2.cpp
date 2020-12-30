// A part of this code is taken from https://www.geeksforgeeks.org/represent-n-as-the-sum-of-exactly-k-powers-of-two-set-2/
// C++ implementation of the above approach 
// #include <iostream> 
#include <bits/stdc++.h>
using namespace std; 

// Function to print k numbers which are powers of two 
// and whose sum is equal to n 
void FindAllElements(int n, int k) 
{ 
	// Initialising the sum with k 
	int sum = k; 

	// Initialising an array A with k elements 
	// and filling all elements with 1 
	int A[k]; 
	fill(A, A + k, 1); 

	for (int i = k - 1; i >= 0; --i) { 

		// Iterating A[] from k-1 to 0 
		while (sum + A[i] <= n) { 

			// Update sum and A[i] 
			// till sum + A[i] is less than equal to n 
			sum += A[i]; 
			A[i] *= 2; 
		} 
	} 

	// Impossible to find the combination 
	if (sum != n) { 
		cout << "-1" << endl; 
	} 

	// Possible solution is stored in A[] 
	else { 
		for (int i = 0; i < k; ++i) {
            char ch = ((int)(log2(A[i]))) + 97;
            printf("%c",ch);
        }
		printf("\n");
	} 
} 

// Driver code 
int main() 
{ 
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        FindAllElements(k,n);
    }
    
	// int n = 12; 
	// int k = 6; 
	// FindAllElements(n, k); 

	return 0; 
} 
