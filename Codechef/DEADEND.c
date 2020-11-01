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
#define size
#define mod
typedef unsigned long long int ull;
typedef long long int ll;
int gcd(int a, int b){return (a==0)?b:gcd(b % a, a);}
int lcm(int a, int b){return ((a*b)/(gcd(a,b)));}
typedef struct tree
{
    int number;
    int partner;
}tree;
int compare(const void *a, const void *b)
{
    tree * x = (tree *)a;
    tree * y = (tree *)b;
    return x->number-y->number;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        tree * a = (tree *)malloc(sizeof(tree)*n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i].number);
            a[i].partner=-1;
        }
        qsort(a,n,sizeof(tree),compare);
        for(int i=0;i<n;i++)
            printf("%d %d\n",a[i].number,a[i].partner);
        int ans=0;
        if(n==1)
            printf("1\n");
        else
        {
            if(a[0].number-a[1].number==-1)
            {
                a[0].partner=a[1].number;
                a[1].partner=a[0].number;
            }
            else
            {
                a[0].partner=a[0].number+1;
                ans++;
            }
            for(int i=1;i<n-1;i++)
            {
                if(a[i].partner==-1)
                {
                    if(a[i].number-a[i-1].number==1)
                    {
                        a[i].partner=a[i-1].number;
                    }
                    else if(a[i].number-a[i+1].number==-1)
                    {
                        a[i].partner=a[i+1].number;
                    }
                    else if(a[i-1].partner-a[i].number==-1)
                    {
                        a[i].partner=a[i-1].partner;
                    }
                    else
                    {
                        a[i].partner=a[i].number+1;
                        ans++;
                    }
                }
            }
            if(a[n-1].partner==-1)
            {
                if(a[n-2].partner-a[n-1].number==-1)
                {
                    a[n-1].partner=a[n-2].partner;
                }
                else if(a[n-1].number-a[n-2].number==-1)
                {
                    a[n-1].partner=a[n-2].number;
                }
                else
                {
                    ans++;
                }
            }
            printf("%d\n",ans);
        }
        free(a);
    }
    return 0;
}