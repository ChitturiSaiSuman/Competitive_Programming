/*
 _____   _    _   __    __     ____     __    _
/ ____| | |  | | |  \  /  |   /    \   |  \  | |
| |___  | |  | | |   \/   |  /   _  \  | . \ | |
\____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
____| | | \__/ | | |    | | |   __   | | | \ ` |
|_____/ \______/ |_|    |_| |__|  |__| |_|  \__|

*/
/*
Template by Sai Suman Chitturi
Linkedin: https://www.linkedin.com/in/sai-suman-chitturi-9727a2196/
Hackerrank: skynetasspyder
Codechef: suman_18733097
Codeforces: saisumanchitturi
Github: ChitturiSaiSuman
Hackerearth: chitturi7
SPOJ: Sai Suman Chitturi @out_of_bound
*/
import java.io.*;
import java.util.*;
class FastReader {
    BufferedReader br;
    StringTokenizer st;
    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    String next() {
        while(st==null || !st.hasMoreElements()) {
            try {
                st=new StringTokenizer(br.readLine());
            }
            catch(IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
    int nextInt() {
        return Integer.parseInt(next());
    }
    float nextFloat() {
        return Float.parseFloat(next());
    }
    long nextLong() {
        return Long.parseLong(next());
    }
    double nextDouble() {
        return Double.parseDouble(next());
    }
    String nextLine() {
        String str="";
        try{
            str=br.readLine();
        }
        catch(IOException e){
            e.printStackTrace();
        }
        return str;
    }
}
class Sieve {
    int mxN;
    boolean isPrime[];
    int spf[];
    int phi[];
    Sieve(int mxN) {
        this.mxN = mxN;
        isPrime = new boolean[mxN];
        spf = new int[mxN];
        phi = new int[mxN];
        Arrays.fill(isPrime,false);
        for(int i=0;i<mxN;i++)
            spf[i] = phi[i] = i;
        for(int i=2;i<mxN;i++)
            if(phi[i]==i)
                for(int j=i;j<mxN;j+=i)
                    phi[j] -= phi[j]/i;
        for(int i=3;i<mxN;i+=2)
            isPrime[i] = true;
        isPrime[2] = true;
        for(int i=3;i*i<mxN;i+=2)
            if(isPrime[i])
                for(int j=i*i;j<mxN;j+=i)
                    isPrime[j] = false;
        for(int i=2;i<mxN;i+=2)
            spf[i] = 2;
        for(int i=3;i*i<mxN;i+=2)
            if(spf[i]==i)
                for(int j=i*i;j<mxN;j+=i)
                    if(spf[j]==j)
                        spf[j] = i;
    }
    public int factorize(int n) {
        int ans = 1;
        while(n>1) {
            int temp = spf[n];
            int c = 0;
            while(temp==spf[n]) {
                n/=spf[n];
                c++;
            }
            ans*=c+1;
        }
        return ans;
    }
    public static boolean check(int n) {
        if(n==0 || n==1)
            return false;
        else if(n==2 || n==3)
            return true;
        else if(n%2==0 || n%3==0)
            return false;
        for(int i=5;i*i<=n;i+=6)
            if(n%i==0 || n%(i+2)==0)
                return false;
        return true;
    }
}
class Graph {
    int V, E;
    LinkedList<Integer> graph[];
    Graph(int V, int E) {
        this.V = V+1;
        this.E = E;
        graph = new LinkedList[this.V];
        for(int i=0;i<this.V;i++) {
            graph[i] = new LinkedList<Integer>();
        }
    }
    public void addEdge(int a, int b) {
        this.graph[a].add(b);
        this.graph[b].add(a);
    }
    public void bfs(int start, int end) {
        Queue<Integer> queue = new LinkedList<Integer>();
        boolean visited[] = new boolean[this.V];
        Arrays.fill(visited,false);
        queue.add(start);
        visited[start] = true;
        while(!queue.isEmpty() && !visited[end]) {
            start = queue.poll();
            for(int vertex: this.graph[start]) {
                if(!visited[vertex]) {
                    visited[vertex] = true;
                    queue.add(vertex);
                }
            }
        }
    }
    public void dfs(int start, int end) {
        Stack<Integer> stack = new Stack<Integer>();
        boolean visited [] = new boolean[this.V];
        Arrays.fill(visited,false);
        visited[start] = true;
        stack.add(start);
        while(!visited[end] && !stack.isEmpty()) {
            start = stack.pop();
            for(int vertex: this.graph[start]) {
                if(!visited[vertex]) {
                    visited[vertex] = true;
                    stack.add(vertex);
                }
            }
        }
    }
}
class Main {
    static final int mod = (int)(1e9+7);
    static final long hell = (long)(1e18);
    static FastReader scan;
    static int min(int a, int b) {
        return a<b?a:b;
    }
    static int max(int a, int b) {
        return a>b?a:b;
    }
    static long min(long a, long b) {
        return a<b?a:b;
    }
    static long max(long a, long b) {
        return a>b?a:b;
    }
    static long gcd(long a, long b) {
        for(long rem;b>0;rem=a%b,a=b,b=rem);
        return a;
    }
    static long lcm(long a, long b) {
        return (a*b)/gcd(a,b);
    }
    static int add(int a, int b) {
        return (a%mod+b%mod)%mod;
    }
    static long add(long a, long b) {
        return (a%mod+b%mod)%mod;
    }
    static int sub(int a, int b) {
        return (a%mod-b%mod+mod)%mod;
    }
    static long sub(long a, long b) {
        return (a%mod-b%mod+mod)%mod;
    }
    static int mul(int a, int b) {
        return (a%mod*b%mod)%mod;
    }
    static long mul(long a, long b) {
        return (a%mod*b%mod)%mod;
    }
    static int inverse(int a) {
        return power(a,mod-2,mod);
    }
    static int inverse(int a, int p) {
        return power(a,p-2,p);
    }
    static long inverse(long a) {
        return power(a,mod-2,mod);
    }
    static long inverse(long a, long p) {
        return power(a,p-2,p);
    }
    static void error(Object obj) {
        System.err.print(obj+" ");
    }
    static void read(int arr[], int mxN) {
        for(int i=0;i<mxN;i++)
            arr[i] = scan.nextInt();
    }
    static void read(float arr[], int mxN) {
        for(int i=0;i<mxN;i++)
            arr[i] = scan.nextFloat();
    }
    static void read(double arr[], int mxN) {
        for(int i=0;i<mxN;i++)
            arr[i] = scan.nextDouble();
    }
    static void read(long arr[], int mxN) {
        for(int i=0;i<mxN;i++)
            arr[i] = scan.nextLong();
    }
    static void write(int arr[], int mxN) {
        for(int i=0;i<mxN;i++)
            System.out.print(arr[i]+" ");
    }
    static void write(long arr[], int mxN) {
        for(int i=0;i<mxN;i++)
            System.out.print(arr[i]+" ");
    }
    static void write(float arr[], int mxN) {
        for(int i=0;i<mxN;i++)
            System.out.print(arr[i]+" ");
    }
    static void write(double arr[], int mxN) {
        for(int i=0;i<mxN;i++)
            System.out.print(arr[i]+" ");
    }
    static void print(Object obj) {
        System.out.print(obj);
    }
    static void println() {
        System.out.println();
    }
    static void println(Object obj) {
        System.out.println(obj);
    }
    static int binarySearch(int a[], int n, int key) {
        int lb = 0;
        int ub = n-1;
        while(lb<=ub) {
            int mid = (lb+ub)/2;
            if(a[mid]==key)
                return mid;
            else if(a[mid]<key)
                lb = mid+1;
            else
                ub = mid-1;
        }
        return -1;
    }
    static void matmul(int a[][], int b[][], int res[][], int p) {
        int M = a.length;
        int N = a[0].length;
        int P = b[0].length;
        int result[][] = new int[M][P];
        for(int i=0;i<M;i++) {
            for(int j=0;j<P;j++) {
                result[i][j] = 0;
                for(int k=0;k<N;k++) {
                    result[i][j] = (result[i][j]%p + (a[i][k]%p*b[k][j]%p)%p)%p;
                }
            }
        }
        for(int i=0;i<M;i++)
            for(int j=0;j<P;j++)
                res[i][j] = result[i][j];
    }
    static void matmul(long a[][], long b[][], long res[][], long p) {
        int M = a.length;
        int N = a[0].length;
        int P = b[0].length;
        long result[][] = new long[M][P];
        for(int i=0;i<M;i++) {
            for(int j=0;j<P;j++) {
                result[i][j] = 0;
                for(int k=0;k<N;k++) {
                    result[i][j] = (result[i][j]%p + (a[i][k]%p*b[k][j]%p)%p)%p;
                }
            }
        }
        for(int i=0;i<M;i++)
            for(int j=0;j<P;j++)
                res[i][j] = result[i][j];
    }
    static int power(int x, int y, int p) {
        int result = 1;
        for(;y>0;y>>=1,x=(x*x)%p) 
            if((y&1)==1)
                result = (result*x)%p;
        return result;
    }
    static long power(long x, long y, long p) {
        long result = 1;
        for(;y>0;y>>=1,x=(x*x)%p)
            if((y&1)==1)
                result = (result*x)%p;
        return result;
    }
    static int[][] power(int a[][], int y, int p) {
        int result[][] = new int[a.length][a.length];
        for(int i=0;i<a.length;i++)
            result[i][i] = 1;
        for(;y>0;y>>=1,matmul(a,a,a,p)) {
            if((y&1)==1)
                matmul(a,result,result,p);
        }
        return result;
    }
    static long[][] power(long a[][], long y, long p) {
        long result[][] = new long[a.length][a.length];
        for(int i=0;i<a.length;i++)
            result[i][i] = 1;
        for(;y>0;y>>=1,matmul(a,a,a,p)) {
            if((y&1)==1)
                matmul(a,result,result,p);
        }
        return result;
    }
    static long nthFibonacci(long n) {
        long base[][] = {{1,1},{1,0}};
        return power(base,n,mod)[0][1];
    }
    static void solve() {
        return;
    }
    public static void main(String[] args) {
        scan = new FastReader();
        int t = -1;
        t = 0;
        if(t==0)
            t = scan.nextInt();
        for(int test = 0;test<t;test++) {
            // System.out.print("Case #"+(test+1)+": ");
            println();
        }
    }
}