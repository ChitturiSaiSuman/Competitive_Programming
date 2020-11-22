#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>
#define size 200005
int compare(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int t;
    scanf("%d",&t);
    int a[size];
    int b[size];
    while(t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        int i;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            b[i]=a[i];
        qsort(b,n,sizeof(int),compare);
        int count=0;
        for(i=0;i<n;i++)
            if(a[i]!=b[i])
                count++;
        if(count%3!=0)
            printf("-1\n");
        else if(count/3>k)
            printf("-1\n");
        else
        {
            
        }
        
    }
}