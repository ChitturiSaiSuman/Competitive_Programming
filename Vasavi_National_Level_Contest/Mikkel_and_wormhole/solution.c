#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<assert.h>
#include<time.h>
#include<limits.h>
#define and &&
#define or ||
#define not !
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define sub(a,b) (((a%mod)-(b%mod))+mod)%mod
#define mul(a,b) ((a%mod)*(b%mod))%mod
#define add(a,b) ((a%mod)+(b%mod))%mod
#define inverse(a) (power(a,mod-2))
#define size 2000003
#define mod 1000000007
typedef long long int ll;
typedef unsigned long long int ull;
ll fact[size]={1};
void pre_compute()
{
    for(int i=1;i<size;i++)
        fact[i]=mul(fact[i-1],i);
}
ll power(ll x, ll y)
{
    ll result=1LL;
    while(y>0)
    {
        if(y&1)
            result = mul(result,x);
        x=mul(x,x);
        y>>=1;
    }
    return result;
}
ll ncr_mod_p(int n, int r)
{
    return mul(fact[n],mul(inverse(fact[n-r]),inverse(fact[r])));
}
ll solve(ll x, ll y, ll x1, ll y1, ll x2, ll y2)
{
    ll total_ways = ncr_mod_p(x+y,y);
    ll q1 = ncr_mod_p(x1+y1,x1);
    ll rx = x-x1;
    ll ry = y-y1;
    ll q2 = 0, w2 = 0, h1 = 0;
    if(rx>=0 and ry>=0)
        q2 = ncr_mod_p(x-x1+y-y1,x-x1);
    ll p1 = mul(q1,q2);
    ll sx = x-x2;
    ll sy = y-y2;
    ll w1 = ncr_mod_p(x2+y2,x2);
    if(sx>=0 and sy>=0)
        w2 = ncr_mod_p(x-x2+y-y2,x-x2);
    ll p2 = mul(w1,w2);
    ll cx = x2-x1;
    ll cy = y2-y1;
    if(cx>=0 and cy>=0)
        h1 = ncr_mod_p(x2-x1+y2-y1,x2-x1);
    ll additional = mul(q1,mul(h1,w2));
    total_ways = sub(add(total_ways,additional),add(p1,p2));
    ll ans = total_ways%mod;
    return ans;
}
int main()
{
    pre_compute();
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int x,y,x1,x2,y1,y2;
        scanf("%d %d %d %d %d %d",&x,&y,&x1,&y1,&x2,&y2);
        printf("%lld\n",solve(x,y,x1,y1,x2,y2));
    }
    return 0;
}