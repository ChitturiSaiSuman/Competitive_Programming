#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<limits.h>
#define or ||
#define and &&
#define not !
#define count_set_bits __builtin_popcount
#define size 1003
#define mod
typedef unsigned long long int ull;
typedef long long int ll;
int gcd(int a, int b){return (a==0)?b:gcd(b % a, a);}
int lcm(int a, int b){return ((a*b)/(gcd(a,b)));}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[size];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int last[size];
        for(int i=0;i<size;i++)
            last[i]=-1;
        int count[size];
        for(int i=0;i<size;i++)
            count[i]=0;
        for(int i=0;i<n;i++)
        {
            if(last[a[i]]==-1)
            {
                last[a[i]]=i;
                count[a[i]]=1;
            }
            else
            {
                if(last[a[i]]-i!=-1)
                {
                    count[a[i]]++;
                    last[a[i]]=i;
                }
            }
        }
        int ans=-1;
        int max=0;
        for(int i=0;i<size;i++)
        {
            if(count[i]>max)
            {
                max=count[i];
                ans=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}