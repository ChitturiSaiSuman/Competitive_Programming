from collections import defaultdict
class Graph:
    def __init__(self):
        self.V = 0
        self.graph = defaultdict(list)
    def addEdge(self,u,v):
        self.graph[u].append(v)
        self.V+=1
    def bfs(self,source):
        visited = [False]*self.V
        queue = [source]
        visited[source]=True
        while queue:
            s = queue.pop(0)
            print(s, end=" ")
            for i in self.graph[s]:
                if not visited[i]:
                    visited[i]=True
                    queue.append(i)