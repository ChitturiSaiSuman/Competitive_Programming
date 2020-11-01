#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n;
        scanf("%d",&n);
        int a[16][16];
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
                scanf("%d",&a[i][j]);
        int dp[16][16];
        dp[0][0]=a[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                {
                    dp[i][j]=dp[i-1][j]+a[i][j];
                }
                else if(j==i)
                {
                    dp[i][j]=dp[i-1][j-1]+a[i][j];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
                }
            }
        }
        int max_value=0;
        for(int i=0;i<n;i++)
            max_value=max(dp[n-1][i],max_value);
        printf("%d\n",max_value);
    }
    return 0;
}