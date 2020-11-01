#include<stdio.h>
#define mod 1000000009
typedef long long int ll;
#define mul(a,b) ((a%mod*b%mod)%mod)
#define add(a,b) ((a%mod+b%mod)%mod)
void matmul(ll a[][2], ll b[][2], ll res[][2])
{
    ll result[2][2];
    result[0][0] = add(mul(a[0][0],b[0][0]),mul(a[0][1],b[1][0]));
    result[0][1] = add(mul(a[0][0],b[0][1]),mul(a[0][1],b[1][1]));
    result[1][0] = add(mul(a[1][0],b[0][0]),mul(a[1][1],b[1][0]));
    result[1][1] = add(mul(a[1][0],b[0][1]),mul(a[1][1],b[1][1]));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            res[i][j]=result[i][j]%(mod);
}
void solve()
{
    int n;
    scanf("%d",&n);
    ll base[2][2] = {{9,1},{8,1}};
    ll result[2][2] = {{1,0},{0,1}};
    while (n>0)
    {
        if(n&1)
            matmul(base,result,result);
        matmul(base,base,base);
        n>>=1;
    }
    ll ans = add(result[0][0],result[0][1]);
    printf("%lld\n",ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
        solve();
    return 0;
}