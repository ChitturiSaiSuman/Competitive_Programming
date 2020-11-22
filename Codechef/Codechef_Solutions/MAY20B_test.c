#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define size 32
int main()
{
    srand(time(0));
    int l,r,ans,a,b,value,temp;
    int i;
    int t=10;
    while(t)
    {
        a=rand()%size;
        b=rand()%size;
        if(a>b)
            a=(a+b)-(b=a);
        l=rand()%size;
        r=rand()%size;
        if(l>r)
            l=(l+r)-(r=l);
        ans=l;
        value=0;
        for(i=l;i<=r;i++)
        {
            temp=(a&i)*(b&i);
            if(temp>value)
            {
                value=temp;
                ans=i;
            }
        }
        if(a>=l && a<=r && b<=r && b>=l)
        {
            printf("Special: %d %d %d %d: %d\n",a,b,l,r,ans);
            t-=1;
        }
        //printf("%d %d %d %d: %d, %d\n",a,b,l,r,ans,value);
    }
}