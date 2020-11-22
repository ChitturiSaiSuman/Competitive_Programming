import java.io.*;
import java.util.*;
class Extended{
    static final int mod = 1000000007;
    static final int size = 1000001;
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreElements()){
                try{
                    st=new StringTokenizer(br.readLine());
                }
                catch(IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        float nextFloat(){
            return Float.parseFloat(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
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
    public static void main(String[] args){
        
    }
}
class Sieve{
    int spf[];
    int prime[];
    int count[];
    long sum[];
    void generate_primes(int n){
        prime = new int[n];
        count = new int[n];
        sum = new long[n];
        Arrays.fill(prime,0);
        Arrays.fill(count,0);
        Arrays.fill(sum,0);
        prime[2]=1;
        for(int i=3;i<n;i+=2)
            prime[i]=1;
        for(int i=3;i*i<n;i+=2)
            if(prime[i]==1)
                for(int j=i*i;j<n;j+=i)
                    prime[j]=0;
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+i*prime[i];
            count[i]=count[i]+prime[i];
        }
    }
    void generate_spf(int n){
        spf = new int[n];
        for(int i=0;i<n;i++)
            spf[i]=i;
        for(int i=4;i<n;i+=2)
            spf[i]=2;
        for(int i=3;i*i<n;i+=2)
            if(spf[i]==i)
                for(int j=i*i;j<n;j+=i)
                    if(spf[j]==j)
                        spf[j]=i;
    }
    int factorise(int n){
        int ans=1;
        int c=0;
        while(n%2==0){
            n/=2;
            c++;
        }
        ans*=c+1;
        c=0;
        while(n%3==0){
            n/=3;
            c++;
        }
        ans*=c+1;
        for(int i=5;i<=Math.sqrt(n);i+=6){
            c=0;
            while(n%i==0){
                n/=i;
                c++;
            }
            ans*=c+1;
            c=0;
            while(n%(i+2)==0){
                n/=(i+2);
                c++;
            }
            ans*=c+1;
        }
        if(n>2)
            ans*=2;
        return ans;
    }
    int factor(int n){
        int ans=1;
        while(n>1){
            int temp=spf[n];
            int c=0;
            while(spf[n]==temp){
                n/=spf[n];
                c++;
            }
            ans*=c+1;
        }
        return ans;
    }
}