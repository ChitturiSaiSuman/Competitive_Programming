#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define is ==
#define and &&
#define or ||
#define not !
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
typedef long long int ll;
int get_bit(const int n)
{
    int small=10;
    int large=-1;
    int temp=n;
    while(temp>0)
    {
        small=min(small,temp%10);
        temp/=10;
    }
    temp=n;
    while(temp>0)
    {
        large=max(large,temp%10);
        temp/=10;
    }
    int ans=large*11+small*7;
    int digit1=ans%10;
    ans/=10;
    int digit2=ans%10;
    ans=(digit2*10+digit1);
    return ans;
}
int msb(int n)
{
    n/=10;
    return n;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[502];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int bit[502];
    for(int i=0;i<n;i++)
    {
        bit[i]=get_bit(a[i]);
        //printf("%d ",bit[i]);
    }
    int ans=0;
    for(int m=0;m<10;m++)
    {
        int count1=0;
        for(int i=0;i<n;i+=2)
        {
            if(msb(bit[i])==m)
                count1++;
        }
        int count2=0;
        for(int i=1;i<n;i+=2)
        {
            if(msb(bit[i])==m)
                count2++;
        }
        if(count1>2 or count2>2)
            ans+=2;
        else if(count1==2 or count2==2)
            ans+=1;
    }
    printf("%d",ans);
    return 0;
}