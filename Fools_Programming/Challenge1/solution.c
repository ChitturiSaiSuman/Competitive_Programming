#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<limits.h>
#define size
#define mod
#define or ||
#define and &&
typedef unsigned long long int ull;
typedef long long int ll;
int myfun(int n, int k)
{
    int temp,i,ans=INT_MAX;
    int power;
    int count;
    int div;
    int c;
    if(k%2==0)
    {
        power=0;
        while(k%2==0)
        {
            k/=2;
            power++;
        }
        temp=n;
        c=0;
        while(temp>=2)
        {
            temp/=2;
            c+=temp;
        }
        div=c/power;
        if(div<ans)
            ans=div;
    }
    for(i=3;i<=sqrt(k);i++)
    {
        if(k%i==0)
        {
            power=0;
            while(k%i==0)
            {
                k/=i;
                power++;
            }
            temp=n;
            c=0;
            while(temp>=i)
            {
                temp/=i;
                c+=temp;
            }
            div=c/power;
            if(div<ans)
                ans=div;
        }
    }
    if(k>2)
    {
        c=0;
        temp=n;
        while(temp>=k)
        {
            temp/=k;
            c+=temp;
        }
        if(c<ans)
            ans=c;
    }
    return ans;
}
int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        printf("%d\n",myfun(n,k));
    }
    return 0;
}
