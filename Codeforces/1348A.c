#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void solve(int n)
{
    long long sum1=0;
    long long sum2=0;
    long long total=0;
    for(int i=1;i<=n;i++)
        total+=pow(2,i);
    for(int i=1;i<n/2;i++)
        sum1+=pow(2,i);
    sum1+=pow(2,n);
    sum2=total-sum1;
    printf("%lld\n",(sum1>sum2?sum1-sum2:sum2-sum1));
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        solve(n);
    }
    return 0;
}