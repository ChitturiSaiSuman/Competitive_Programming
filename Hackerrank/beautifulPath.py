from sys import stdin, stdout
from collections import defaultdict
from typing import DefaultDict

class IO:
    def String(self):
        return stdin.readline().strip()
    def Int(self):
        return int(self.String())
    def Tuple(self):
        return tuple(map(int,self.String().split()))
    def List(self):
        return list(map(int,self.String().split()))
    def write(self,*args, sep = " ", end = "\n"):
        string = sep.join([str(i) for i in args]) + end
        stdout.write(string)

class Graph:
    def __init__(self,V,E):
        self.V = V
        self.E = E
        self.graph = defaultdict(list)
        self.weight = defaultdict(tuple)
        self.costs = []
    def addEdge(self,a,b,c):
        self.graph[a].append(b)
        self.weight[(a,b)] = c
        self.weight[(b,a)] = c
    def dfs(self,start,visited,end,currentCost):
        for i in self.graph[start]:
            if i == end:
                currentCost |= self.weight[(start,i)]
                self.costs.append(currentCost)
                return
            if not visited[i]:
                visited[i] = True
                self.dfs(i,visited,end,currentCost|self.weight[(start,i)])

    def solve(self,a,b):
        visited = [False]*self.V
        start = a
        end = b
        cost = 0
        visited[a] = True
        self.dfs(a,visited,b,cost)
        try:
            ans = min(self.costs)
        except:
            ans = -1
        return ans


def main():
    io = IO()
    m,n = io.Tuple()
    g = Graph(m,n)
    for i in range(n):
        a,b,c = io.Tuple()
        g.addEdge(a-1,b-1,c)
    # io.write(g.weight)
    a,b = io.Tuple()
    io.write(g.solve(a-1,b-1))
    # io.write()
main()