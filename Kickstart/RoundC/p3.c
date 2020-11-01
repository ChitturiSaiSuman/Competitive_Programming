#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>
#define or ||
#define and &&
#define size 100007
typedef long long int ll;
typedef unsigned long long int ull;
bool isPerfectSquare(long long int x) 
{
    long double sr = sqrt(x);
    return((sr - floor(sr)) == 0); 
} 
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n;
        scanf("%d",&n);
        int a[size];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=a[j];
                if(isPerfectSquare(sum))
                    ans++;
            }
        }
        printf("Case #%d: %d\n",test,ans);
    }
    return 0;
}