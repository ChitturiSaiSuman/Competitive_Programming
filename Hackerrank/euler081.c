#include<stdio.h>
#include<stdlib.h>
#define size 1007
long long int min(long long int a, long long int b)
{
    return (a>b?a:b);
}
int main()
{
    int a[size][size];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    long long int dp[size][size];
    dp[0][0]=a[0][0];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=dp[i-1][0]+a[i][0];
        dp[0][i]=dp[0][i-1]+a[0][i];
    }
    for(int i=1;i<n;i++)
        for(int j=1;j<n;j++)
            dp[i][j]=min(dp[i][j-1],dp[i-1][j])+a[i][j];
    printf("%lld",dp[n-1][n-1]);
}