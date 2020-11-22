#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#define and &&
#define or ||
#define not !
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define SIZE
#define MOD
typedef unsigned long long int ull;
typedef long long int ll;
int compare(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int *a;
        a=(int *)malloc(sizeof(int)*n);
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==m-1)
                flag=true;
        }
        int ans=0;
        if(not flag)
            printf("-1\n");
        else
        {
            qsort(a,n,sizeof(int),compare);
            int i=0;
            while(i<n and a[i]<m)
                i++;
            int ind=i;
            i--;
            while (i>0 and a[i]-a[i-1]<2)
            {
                i--;
                ans++;
            }
            ans++;
            while(ind<n and a[ind]==m)
                ind++;
            ans+=n-ind;
            if(ans==0)
                printf("-1\n");
            else
                printf("%d\n",ans);
        }
        free(a);
    }
    return 0;
}