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
class Main {
    static class FastReader {
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
    
    static final int mod = 1000000007; // 10**9+7

    static int mul(int a, int b) {
        return ((int)(((long)(a%mod))*((long)(b%mod)))%mod);
    }
    static long mul(long a, long b) {
        return (a%mod*b%mod)%mod;
    }
    static int add(int a, int b) {
        return ((int)((long)(a%mod)+(long)(b%mod))%mod);
    }
    static long add(long a, long b) {
        return (a%mod+b%mod)%mod;
    }
    static int sub(int a, int b) {
        return ((int)(((long)(mod)+a%mod-b%mod))%mod);
    }
    static long sub(long a, long b) {
        return (mod+a%mod-b%mod)%mod;
    }
    static long power(long x, long y) {
        x%=mod;
        if(x<2)
            return x;
        long result = 1;
        while(y>0) {
            if((y&1)==1)
                result = mul(result,x);
            x = mul(x,x);
            y>>=1;
        }
        return result;
    }
    static long sum(int a[]) {
        long s = 0;
        for(int i:a)
            s+=i;
        return s;
    }
    static long sum(long a[]) {
        long s = 0;
        for(long i:a)
            s+=i;
        return s;
    }
    static double sum(double a[]) {
        double s = 0;
        for(double i:a)
            s+=i;
        return s;
    }
    static HashMap<Integer,Integer> counter(int a[]) {
        HashMap<Integer,Integer> count = new HashMap<Integer,Integer>();
        for(int i:a) {
            try {
                count.put(i,count.get(i)+1);
            } catch (Exception e) {
                count.put(i,1);
            }
        }
        return count;
    }
    static HashMap<Character,Integer> counter(char a[]) {
        HashMap<Character,Integer> count = new HashMap<Character,Integer>();
        for(char i:a) {
            try {
                count.put(i,count.get(i)+1);
            } catch (Exception e) {
                count.put(i,1);
            }
        }
        return count;
    }
    static HashMap<String,Integer> counter(String a[]) {
        HashMap<String,Integer> count = new HashMap<String,Integer>();
        for(String i:a) {
            try {
                count.put(i,count.get(i)+1);
            } catch (Exception e) {
                count.put(i,1);
            }
        }
        return count;
    }
    static long inverse(long a) {
        return power(a,mod-2);
    }

    static final int size = 1000001; // 10**6+1
    static boolean prime[];
    static int prime_count[];
    static long fact[];
    static int spf[];
    
    static void computeFactorials(int n) {
        fact = new long[n];
        fact[0]=1;
        for(int i=1;i<n;i++)
            fact[i] = mul(fact[i-1],i);
    }
    static void sieve(int n) {
        prime = new boolean[n];
        prime_count = new int[n];
        Arrays.fill(prime,false);
        for(int i=3;i*i<n;i+=2)
            prime[i]=true;
        for(int i=3;i*i<n;i+=2)
            if(prime[i])
                for(int j=i*i;j<n;j+=i)
                    prime[j]=false;
        prime[2]=true;
        prime_count[0]=0;
        for(int i=1;i<n;i++)
            prime_count[i]=prime_count[i-1]+(prime[i]?1:0);
    }
    static void computeSPF(int n) {
        spf = new int[n];
        for(int i=1;i<n;i+=2)
            spf[i]=i;
        for(int i=2;i<n;i+=2)
            spf[i]=2;
        for(int i=3;i*i<size;i+=2)
            if(spf[i]==i)
                for(int j=i*i;j<n;j+=i)
                    if(spf[j]==j)
                        spf[j]=i;
    }
    static int factor(int n) {
        int ans=1;
        int c=0;
        while(n%2==0) {
            c++;
            n/=2;
        }
        ans*=c+1;
        for(int i=3;i*i<=n;i+=2) {
            c=0;
            while(n%i==0) {
                n/=i;
                c++;
            }
            ans*=c+1;
        }
        if(n>2)
            ans*=2;
        return ans;
    }
    static int factorise(int n) {
        int ans=1;
        while(n>1) {
            int temp=spf[n];
            int c=0;
            while(temp==spf[n]) {
                n/=spf[n];
                c++;
            }
            ans*=c+1;
        }
        return ans;
    }
    static void dot(long a[][], long b[][], long result[][]) {
        long res[][] = {{0,0},{0,0}};
        res[0][0] = add(mul(a[0][0],b[0][0]),mul(a[0][1],b[1][0]));
        res[0][1] = add(mul(a[0][0],b[0][1]),mul(a[0][1],b[1][1]));
        res[1][0] = add(mul(a[1][0],b[0][0]),mul(a[1][1],b[1][0]));
        res[1][1] = add(mul(a[1][0],b[0][1]),mul(a[1][1],b[1][1]));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                result[i][j]=res[i][j];
    }
    static long nth_fibonacci(long n) {
        if(n<2)
            return n;
        long base[][] = {{1,1},{1,0}};
        long result[][] = {{1,0},{0,1}};
        while(n>0) {
            if((n&1)==1)
                dot(base,result,result);
            dot(base,base,base);
            n>>=1;
        }
        return result[0][1];
    }
    static int binarySearch(Object obj[], int lb, int ub, Object key) {
        return Arrays.binarySearch(obj, lb, ub, key);
    }
    public static void main(String[] args) {
        FastReader scan = new FastReader();
        int t = scan.nextInt();
        for(int test=0;test<t;test++) {
            int n = scan.nextInt();
            System.out.println(n);
        }
    }
}
