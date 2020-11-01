import java.util.*;
class Graph{
    int V;
    LinkedList<Integer>[] adj;
    Graph(int v){
        this.V = v;
        this.adj = new LinkedList[v];
        for(int i=0;i<v;i++){
            adj[i]= new LinkedList<Integer>();
        }
    }
    void addEdge(int u, int v){
        this.adj[u].add(v);
    }
    void bfs(int s){
        boolean visited [] = new boolean[this.V];
        Arrays.fill(visited,false);
        LinkedList<Integer> queue = new LinkedList<Integer>();
        queue.add(s);
        visited[s]=true;
        while(!queue.isEmpty()){
            s = queue.poll();
            System.out.println(s+" ");
            for(int i:adj[s]){
                if(!visited[i]){
                    visited[i]=true;
                    queue.add(i);
                }
            }
        }
    }
}
