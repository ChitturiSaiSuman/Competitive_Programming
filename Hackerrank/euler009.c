#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>
#define max(a,b) (a>b?a:b)
typedef long long int ll;
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n;
        scanf("%d",&n);
        int ans=-1;
        for(int a=1;a<n;a++)
        {
            for(int b=a+1;b<(n-a);b++)
            {
                int c=n-(a+b);
                //printf("%d %d %d\n",a,b,c);
                if(a>0 && b>0 && c>0 && a*a+b*b==c*c)
                    ans=max(a*b*c,ans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}