"""
Author: Chitturi Sai Suman
Created: 2021-02-05 18:39:47
"""
from collections import defaultdict
from math import sqrt
from numpy import cumsum
from math import factorial

def sieve(n):
    prime = [0]*n
    prime[2] = 1
    for i in range(3, n, 2):
        prime[i] = 1
    for i in range(3, int(sqrt(n))+1, 2):
        if prime[i] == 1:
            for j in range(i*i, n, i):
                prime[j] = 0
    return cumsum(prime)

print(sieve(2022)[2021])