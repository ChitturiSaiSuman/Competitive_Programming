#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<limits.h>
#define or ||
#define and &&
#define not !
#define count_set_bits __builtin_popcount
#define size
#define mod
typedef unsigned long long int ull;
typedef long long int ll;
int gcd(int a, int b){return (a==0)?b:gcd(b % a, a);}
int lcm(int a, int b){return ((a*b)/(gcd(a,b)));}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll a,b,l,r;
        scanf("%lld %lld %lld %lld",&a,&b,&l,&r);
        ll value=(a&l)*(b&l);
        ll ans=l;
        for(ll i=l+1;i<=r;i++)
        {
            ll temp=(a&i)*(b&i);
            if(temp>value)
            {
                value=temp;
                ans=i;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}