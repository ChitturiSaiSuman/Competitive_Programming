#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#define and &&
#define or ||
#define not !
#define is ==
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define size ((int)(2*(1e5+1)))
#define mod ((int)(1e9+7))
typedef long long int ll;
void solve()
{
    int n;
    int a[size];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    if(n==1)
        printf("%d\n",1);
    else
    {
        int ans = 0;
        int max_so_far = a[0];
        if(a[0]>a[1])
            ans++;
        for(int i=1;i<n-1;i++)
        {
            if(a[i]>max_so_far and a[i]>a[i+1])
            {
                ans++;
                max_so_far=a[i];
            }
        }
        if(a[n-1]>max_so_far)
            ans++;
        printf("%d\n",ans);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test = 0 ; test < t; test++)
    {
        printf("Case #%d: ",test+1);
        solve();
    }
    return 0;
}