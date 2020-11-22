#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define size 100007
int compare(const void *a, const void *b)
{
    return (*(int *)a-*(int *)b);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n;
        long long int k;
        scanf("%d %lld",&n,&k);
        int a[size];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        long long int ans=0;
        qsort(a,n,sizeof(int),compare);
        for(int i=0;i<n;i++)
        {
            long long int p=a[i];
            while(k<p)
            {
                p=p-k;
                k*=2;
                p*=2;
                if(p>a[i])
                    p=a[i];
                ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}