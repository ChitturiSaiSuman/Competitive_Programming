import java.util.*;
class Graph {
    class Node {
        LinkedList<Integer> friends;
        Node(){
            friends = new LinkedList<Integer>();
        }
        void addFriend(int id) {
            this.friends.add(id);
        }
    }
    Node []graph;
    int V;
    Graph(int n){
        this.graph = new Node[n+1];
        this.V = n;
        for(int i=0;i<n+1;i++)
            this.graph[i] = new Node();
    }
    void addEdge(int u, int v){
        this.graph[u].addFriend(v);
        this.graph[v].addFriend(u);
    }
    boolean bfs(int u, int v){
        if(u==v)
            return true;
        boolean visited [] = new boolean[this.V+1];
        Arrays.fill(visited,false);
        LinkedList<Integer> queue = new LinkedList<Integer>();
        queue.add(u);
        visited[u]=true;
        while(!visited[v] && !queue.isEmpty()){
            u = queue.poll();
            System.out.print(u+" ");
            for(int i:this.graph[u].friends){
                if(!visited[i]){
                    queue.add(i);
                    visited[i]=true;
                }
            }
        }
        System.out.println();
        return visited[v];
    }
    boolean dfs(int u,int v){
        if(u==v)
            return true;
        boolean visited[] = new boolean[this.V+1];
        Arrays.fill(visited,false);
        Stack<Integer> stack = new Stack<Integer>();
        stack.add(u);
        while(!visited[v] && !stack.isEmpty()){
            u = stack.pop();
            if(!visited[u]){
                System.out.print(u+" ");
                visited[u]=true;
            }
            for(int i:this.graph[u].friends){
                if(!visited[i])
                    stack.push(i);
            }
        }
        System.out.println();
        return visited[v];
    }
}
public class test {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Number of Vertices: ");
        int V = scan.nextInt();
        Graph g = new Graph(V);
        System.out.print("Enter Number of Edges: ");
        int E = scan.nextInt();
        for(int e=0;e<E;e++){
            int u,v;
            System.out.print("Enter Edge: ");
            u = scan.nextInt();
            v = scan.nextInt();
            g.addEdge(u, v);
        }
        System.out.print("Enter Number of Queries: ");
        int q = scan.nextInt();
        while(q>0){
            q--;
            int u,v;
            u = scan.nextInt();
            v = scan.nextInt();
            System.out.println(g.dfs(u,v));
        }
        scan.close();
    }
}