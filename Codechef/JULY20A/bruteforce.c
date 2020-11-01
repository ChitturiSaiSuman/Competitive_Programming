#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
int compare(const void *a, const void *b)
{
    return *(int *)b-*(int *)a;
}
void bruteforce(int a[],int n, int k)
{
    int number_of_days=0;
    for(int i=0;i<n;i++)
    {
        int infected=a[i];
        while(k<infected)
        {
            infected-=k;
            k*=2;
            infected*=2;
            if(infected>a[i])
                infected=a[i];
            number_of_days++;
            for(int j=i+1;j<n;j++)
            {
                if()
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        int a[100];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        qsort(a,n,sizeof(int),compare);
        bruteforce(a,n,k);
    }
    return 0;
}