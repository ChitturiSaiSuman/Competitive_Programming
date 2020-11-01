class Main
{
    public static void main(String[] args) {
        long fact[]= new long[100];
        fact[0]=1;
        for(int i=1;i<100;i++){
            fact[i]=fact[i-1]*i;
            if(fact[i]<fact[i-1])
                System.out.println("error"+i);
            System.out.println(i+" "+fact[i]);
        }
    }
}