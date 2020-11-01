#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>
#define or ||
#define and &&
#define not !
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define mod 1000000007
#define size 2000000
typedef long long int ll;
typedef struct pair
{
    long bit;
    int count;
    long value;
}pair;
int compare(const void *a, const void *b)
{
    pair *pair1= (pair *)a;
    pair *pair2 = (pair *)b;
    if(pair1->value!=pair2->value)
    {
        if(pair2->value-pair1->value>0)
            return 1;
        else
            return -1;
    }
    if(pair1->bit - pair2->bit>0)
        return 1;
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        int a[100005];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int count[33]={0};
        for(int i=0;i<n;i++)
        {
            int j=0;
            while (a[i]>0)
            {
                count[j]+=a[i]%2;
                j++;
                a[i]/=2;
            }
        }
        pair mypair[33];
        for(int i=0;i<33;i++)
        {
            mypair[i].bit=((long int)pow(2,i));
            mypair[i].count=count[i];
            mypair[i].value=mypair[i].bit*mypair[i].count;
        }
        qsort(mypair,33,sizeof(pair),compare);
        long int ans=0;
        for(int i=0;i<k;i++)
        {
            ans+=mypair[i].bit;
        }
        printf("%ld\n",ans);
    }
    return 0;
}