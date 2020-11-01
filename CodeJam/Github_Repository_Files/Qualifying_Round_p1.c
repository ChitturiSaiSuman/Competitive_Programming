#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 105
bool flag[size];
void initialise()
{
    for(int i=0;i<size;++i)
        flag[i]=false;
}
int main()
{
    int t,n,a[size][size];
    int i,j;
    int rows,columns;
    int counter=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        int sum=0;
        for(i=0;i<n;i++)
            sum+=a[i][i];
        rows=0;
        columns=0;
        for(i=0;i<n;i++)
        {
            initialise();
            for(j=0;j<n;j++)
            {
                if(flag[a[i][j]])
                {
                    rows++;
                    break;
                }
                else
                {
                    flag[a[i][j]]=true;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            initialise();
            for(j=0;j<n;j++)
            {
                if(flag[a[i][j]])
                {
                    columns++;
                    break;
                }
                else
                {
                    flag[a[i][j]]=true;
                }
            }
        }
        printf("Case #%d: %d %d %d\n",counter++,sum,rows,columns);
    }
    return 0;
}
