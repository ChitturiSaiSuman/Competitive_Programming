#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define size 2000003
typedef long long int ll;
bool prime[size]={false};
void sieve()
{
    for(int i=3;i<size;i+=2)
        prime[i]=true;
    for(int i=3;i*i<size;i+=2)
        if(prime[i])
            for(int j=i*i;j<size;j+=i)
                prime[j]=false;
    prime[2]=true;
}
ll power(ll x, ll y, ll p)
{
    x %=p;
    if(x==0)
        return 0;
    ll result = 1;
    while(y>0)
    {
        if(y&1)
            result = (result*x)%p;
        x = (x*x)%p;
        y>>=1;
    }
    return result;
}
void solve(int n)
{
    while (!prime[n])
    {
        n--;
    }
    printf("%lld\n",power(2,n-1,((int)(1e9+7))));
}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    for(int test = 0; test<t;test++)
    {
        int n;
        scanf("%d",&n);
        solve(n);
    }
}