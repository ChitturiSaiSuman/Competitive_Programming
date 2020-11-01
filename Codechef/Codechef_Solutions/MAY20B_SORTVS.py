from collections import defaultdict
class Graph:
	def __init__(self,vertices):
		self.V= vertices
		self.graph = defaultdict(list) 
	def addEdge(self,u,v): 
		self.graph[u].append(v)
	def isReachable(self, s, d):
		visited =[False]*(self.V)
		queue=[]
		queue.append(s)
		visited[s] = True
		while queue:
			n = queue.pop(0)
			if n == d:
				return True
			for i in self.graph[n]:
				if visited[i] == False:
					queue.append(i)
					visited[i] = True
		return False
def minSwaps(A,graph):
    count = 0
    for i in range(len(A)-1):
        idx = i
        for j in range(i+1, len(A)):
            if A[j] < A[idx]:
                idx = j
        if A[idx] != A[i]:
            A[idx], A[i] = A[i], A[idx]
            count += 1
            if graph.isReachable(idx,i):
                count-=1
    return count
for test in range(int(input())):
    n,m=map(int,input().split())
    l=list(map(int,input().split()))
    graph=Graph(n)
    for _ in range(m):
        x,y=map(int,input().split())
        graph.addEdge(x-1,y-1)
        graph.addEdge(y-1,x-1)
    print(minSwaps(l,graph))