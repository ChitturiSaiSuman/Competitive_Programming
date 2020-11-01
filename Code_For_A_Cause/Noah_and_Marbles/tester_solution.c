#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<limits.h>
#include<time.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define maxN 100001
#define mod 1000000007
#define or ||
#define and &&
#define not !
typedef long long int ll;
ll gcd(ll a, ll b)
{
    ll rem;
    if(a==0 or b==0)
        return max(a,b);
    while(b>0)
    {
        rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
void solve(int a[], int n, int x)
{
    int diff[maxN];
    for(int i=0;i<n;i++)
        diff[i]=abs(a[i]-x);
    ll answer = diff[0];
    for(int i=1;i<n;i++)
        answer = gcd(answer,diff[i]);
    printf("%lld\n",answer);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[maxN];
        int n,x;
        scanf("%d %d",&n,&x);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        solve(a,n,x);
    }
}