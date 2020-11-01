#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>
#include<time.h>
#define size 1000006
#define mod 1000000007
typedef long long int ll;
int prime[size]={0};
int count[size]={0};
void sieve()
{
    for(int i=3;i<size;i+=2)
        prime[i]=1;
    for(int i=3;i*i<size;i+=2)
        if(prime[i])
            for(int j=i*i;j<size;j+=i)
                prime[j]=0;
    prime[2]=1;
    for(int i=1;i<size;i++)
        count[i]=count[i-1]+prime[i];
}
ll power(ll x, ll y)
{
    x=x%mod;
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
int solve(int n)
{
    if(n==1)
        return 0;
    return ((int)power(2,count[n]-1));
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
        printf("%d\n",solve(n));
    }
    return 0;
}