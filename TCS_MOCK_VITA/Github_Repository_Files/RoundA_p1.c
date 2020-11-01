#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 5005
bool flag[size];
int ans[size]={0};
void precalculate()
{
    for(int i=0;i<size;i++)
        flag[i]=false;
    for(int i=1;((i*(i+1))/2)<size;i++)
        flag[(i*(i+1))/2]=true;
    int c=1;
    for(int i=1;i<size;i++)
    {
        if(flag[i])
        {
            ans[i]=c;
            c+=1;
        }
        else
        {
            ans[i]=c;
        }
    }
}
int main()
{
    precalculate();
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}