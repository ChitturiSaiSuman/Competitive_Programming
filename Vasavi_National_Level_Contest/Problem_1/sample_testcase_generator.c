#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#define or ||
#define and &&
#define not !
#define mod 1000000007
#define size 1000007
#define limit 1000000
#define number_of_test_cases 1000000
typedef long long int ll;
int prime[size]={0};
int count[size]={0};
void sieve()
{
    for(int i=3;i<size;i+=2)
        prime[i]=1;
    prime[2]=1;
    for(int i=3;i*i<=size;i+=2)
        if(prime[i])
            for(int j=i*i;j<size;j+=i)
                prime[j]=0;
    for(int i=1;i<size;i++)
        count[i]=count[i-1]+prime[i];
}
ll power(ll x, ll y)
{
    x=(x%mod);
    if(x==0)
        return 0;
    ll result=1;
    while (y>0)
    {
        if(y&1)
            result=(result*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return result;
}
int solve(int n)
{
    if(n==1)
        return 0;
    int ans=count[n]-1;
    return ((int)(power(2,ans)));
}
int main()
{
    sieve();
    FILE *in,*out;
    in = fopen("sample_input.txt","w");
    out = fopen("sample_output.txt","w");
    fprintf(in,"3\n");
    fprintf(in,"1\n");
    fprintf(out,"%d\n",solve(1));
    fprintf(in,"3\n");
    fprintf(out,"%d\n",solve(3));
    fprintf(in,"4\n");
    fprintf(out,"%d\n",solve(4));
    fclose(in);
    fclose(out);
    return 0;
}