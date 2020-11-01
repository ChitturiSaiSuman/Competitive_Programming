#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'onesGroups' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. 2D_INTEGER_ARRAY grid
#  2. INTEGER_ARRAY queries
#

number = 0

def isSafe(grid,i,j,visited,n):
    return (i>=0 and i<n and j>=0 and j<n and not visited[i][j] and grid[i][j]==1)

def DFS(grid,i,j,visited,n):
    dc = [-1,0,0,1]
    ds = [0,-1,1,0]
    visited[i][j] = True
    for k in range(4):
        if isSafe(grid,i+dc[k],j+ds[k],visited,n):
            global number
            number+=1
            DFS(grid,i+dc[j],j+ds[k],visited,n)

def onesGroups(grid, queries):
    n = len(grid)
    visited = [[False for i in range(n)] for j in range(n)]
    answer = [0]*len(queries)
    count = dict()
    for i in range(n):
        for j in range(n):
            if not visited[i][j] and grid[i][j]==1:
                global number
                number = 0
                DFS(grid,i,j,visited,n)
                try:
                    count[number+1]+=1
                except:
                    count[number+1] = 1
    for i in range(queries):
        answer[i] = count[queries[i]]
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    grid_rows = int(input().strip())
    grid_columns = int(input().strip())

    grid = []

    for _ in range(grid_rows):
        grid.append(list(map(int, input().rstrip().split())))

    queries_count = int(input().strip())

    queries = []

    for _ in range(queries_count):
        queries_item = int(input().strip())
        queries.append(queries_item)

    result = onesGroups(grid, queries)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
