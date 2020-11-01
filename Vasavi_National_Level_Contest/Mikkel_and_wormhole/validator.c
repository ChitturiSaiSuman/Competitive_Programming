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
#define limit 1000
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
ll dp_approach(int x, int y, int x1, int y1, int x2, int y2)
{
    ll dp[1003][1003];
    int mxN = 1003;
    for(int i=0;i<mxN;i++)
        for(int j=0;j<mxN;j++)
            dp[i][j]=0;
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=1;
            else if(i==x1 && j==y1)
                dp[i][j]=0;
            else if(i==x2 && j==y2)
                dp[i][j]=0;
            else
                dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
        }
    }
    return dp[x][y];
}
int main()
{
    pre_compute();
    srand(time(0));
    int t = 5000;
    for(int test=0;test<t;test++)
    {
        int x,y,x1,x2,y1,y2;
        x1 = rand()%(limit/100)+1;
        y1 = rand()%(limit/100)+1;
        x2 = (rand()%(limit/10)+1)+x1;
        y2 = (rand()%(limit/10)+1)+y1;
        x = (rand()%(limit/10)+1)+x2;
        y = (rand()%(limit/10)+1)+y2;
        if(x>limit or y>limit or x2>=x or y2>=y or x1>=x2 or y1>=y2)
            printf("ERROR\n");
        ll answer1 = solve(x,y,x1,y1,x2,y2);
        ll answer2 = dp_approach(x,y,x1,y1,x2,y2);
        if(answer1!=answer2)
            printf("Not Matching: %d %d %d %d %d %d\n",x,y,x1,y1,x2,y2);
    }
    return 0;
}