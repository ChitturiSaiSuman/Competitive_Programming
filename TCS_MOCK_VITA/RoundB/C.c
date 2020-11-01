#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define or ||
#define and &&
#define not !
int find_ans(int a, int b)
{
    int ans=0;
    while(a>0 and b>0)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
        ans++;
    }
    return ans;
}
int main()
{
    int p,q,r,s;
    scanf("%d %d %d %d",&p,&q,&r,&s);
    int ans=0;
    for(int i=p;i<=q;i++)
    {
        for(int j=r;j<=s;j++)
        {
            ans+=find_ans(i,j);
        }
    }
    printf("%d",ans);
    return 0;
}