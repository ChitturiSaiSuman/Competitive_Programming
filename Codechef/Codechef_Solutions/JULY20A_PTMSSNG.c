#include<stdio.h>
#include<stdlib.h>
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
        int n;
        scanf("%d",&n);
        int *x,*y;
        x=(int *)malloc(sizeof(int)*(4*n-1));
        y=(int *)malloc(sizeof(int)*(4*n-1));
        for(int i=0;i<(4*n-1);i++)
            scanf("%d %d",&x[i],&y[i]);
        qsort(x,4*n-1,sizeof(int),compare);
        qsort(y,4*n-1,sizeof(int),compare);
        int ans1,ans2;
        ans1=ans2=0;
        int i=0;
        while(i<(4*n-1))
        {
            int c=0;
            int element=x[i];
            while(i<(4*n-1) && x[i]==element)
            {
                i++;
                c++;
            }
            if(c%2==1)
            {
                ans1=element;
                break;
            }
        }
        i=0;
        while(i<(4*n-1))
        {
            int c=0;
            int element=y[i];
            while(i<(4*n-1) && y[i]==element)
            {
                i++;
                c++;
            }
            if(c%2==1)
            {
                ans2=element;
                break;
            }
        }
        printf("%d %d\n",ans1,ans2);
        free(x);
        free(y);
    }
    return 0;
}