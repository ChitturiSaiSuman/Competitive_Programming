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
#define size 2000001 // Maximum value of N
#define mod 1000000007 // Value of the modulo
typedef long long int ll;
bool prime[size]={false}; // prime[i] = true if i is prime else false
int answer[size]={0}; // answer[i] = largest prime less than or equal to i
void sieve() // To pre-compute values
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
ll power(ll x, ll y) // calculates pow(x,y) in log(y) time
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
void solve(int n) // driver function to calculate the result
{
    printf("%lld\n",power(2,answer[n]-1));
}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n;
        scanf("%d",&n);
        solve(n);
    }
    return 0;
}
