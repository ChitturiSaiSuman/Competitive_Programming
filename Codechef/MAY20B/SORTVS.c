#include<stdio.h>
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        int a[20];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int count=0;
        int x,y;
        while(m--)
            scanf("%d %d",&x,&y);
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    count++;
                    a[j]=(a[j]+a[j+1])-(a[j+1]=a[j]);
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}