#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define size 100005
typedef unsigned long long int ull;
typedef long long int ll;
bool check_power_of_2(ull n)
{
    int c=0;
    while(n%2==0)
    {
        n/=2;
        c++;
    }
    return c!=1;
}
void solve(int a[],int n)
{
    ll p;
    int ans=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        p=1;
        for(j=i;j<n;j++)
        {
            p*=a[j];
            if(check_power_of_2(p))
                ans++;
        }
    }
    printf("%d\n",ans);
}
int main()
{
    int t,n,a[size];
    int i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        solve(a,n);
    }
    return 0;
}
