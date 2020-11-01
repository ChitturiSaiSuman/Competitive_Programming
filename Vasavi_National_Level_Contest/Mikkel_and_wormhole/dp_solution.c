#include <stdio.h>
#include <stdlib.h>
#define or ||
#define and &&
#define not !
const int mod = 1000000007;
const int size = 1100;
typedef long long int ll;
ll solve(int x, int y, int x1, int y1, int x2, int y2)
{
    ll **dp;
    dp = (ll **)malloc(sizeof(ll *)*size);
    for(int i=0;i<size;i++)
        dp[i] = (ll *)malloc(sizeof(ll)*size);
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            dp[i][j]=0;
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0 or j==0)
                dp[i][j]=1;
            else if((i==x1 and j==y1) or (i==x2 and j==y2))
                dp[i][j]=0;
            else
                dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
        }
    }
    free(dp);
    return dp[x][y];
}
int main()
{
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