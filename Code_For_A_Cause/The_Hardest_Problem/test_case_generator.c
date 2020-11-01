#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<limits.h>
#include<time.h>
#define or ||
#define and &&
#define not !
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define size 2000001
#define mod 1000000007
typedef long long int ll;
bool prime[size]={false};
int answer[size]={0};
void sieve()
{
    for(int i=3;i<size;i+=2)
        prime[i]=true;
    prime[2]=true;
    for(int i=3;i*i<size;i+=2)
        if(prime[i])
            for(int j=i*i;j<size;j+=i)
                prime[j]=false;
    int i=2;
    int k=2;
    while(i<size)
    {
        while(i<size and not prime[i])
            answer[i++]=k;
        k=i;
        answer[i]=k;
        i++;
    }
}
ll power(ll x, ll y)
{
    x = x%mod;
    if(x==0)
        return 0;
    ll result=1;
    while(y>0)
    {
        if(y&1)
            result=(result*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return result;
}
ll solve(int n)
{
    return power(2,answer[n]-1);
}
int main()
{
    sieve();
    srand(time(0));
    char input[]="input00.txt";
    char output[]="output00.txt";
    FILE *in,*out;
    in = fopen(input,"w");
    out = fopen(output,"w");
    int t=1000000;
    fprintf(in,"%d\n",t);
    for(int test=0;test<t;test++)
    {
        int n=rand()%(size-3)+2;
        fprintf(in,"%d\n",n);
        ll answer=solve(n);
        fprintf(out,"%lld\n",answer);
    }
    fclose(in);
    fclose(out);
    return 0;
}