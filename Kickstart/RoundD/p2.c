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
#define size ((int)(2*(1e6+1)))
#define mod ((int)(1e9+7))
typedef long long int ll;
int get_max(int a[])
{
    int ind = 0;
    int max_so_far = a[0];
    for(int i=1;i<4;i++)
        if(a[i]>max_so_far)
        {
            max_so_far = a[i];
            ind = i;
        }
    return ind;
}
void solve()
{
    int n;
    scanf("%d",&n);
    int *a = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans = 0;
    if(n<=4)
        printf("0\n");
    else
    {
        int i;
        for(i=1;i<n;)
        {
            int count =0;
            for(int j=i;j<n && j<i+4;j++)
            {
                if(a[j]>a[j-1])
                    count++;
            }
            if(count==4)
            {
                ans++;
                i+=4;
            }
            else
            {
                count =0;
                for(int j=i;j<n and j<i+4;j++)
                    if(a[j]<a[j-1])
                        count++;
                if(count==4)
                {
                    ans++;
                    i+=4;
                }
                else
                {
                    i++;
                }
            }
        }
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