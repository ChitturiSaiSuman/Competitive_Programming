#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<limits.h>
#include<time.h>
#define and &&
#define or ||
#define not !
#define is ==
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define max_n 1e18
#define test_limit 1000
typedef long long int ll;
int main()
{
    int t;
    scanf("%d",&t);
    for(int test = 0; test < t; test++)
    {
        ll n,p,x=0;
        char s1[10],s2[10];
        scanf("%lld",&n);
        scanf("%s",s1);
        scanf("%s %lld",s2,&x);
        int b[64]={0},j=0,res=0,i;
        p=n;
        bool flag = true;
        while(p)
        {
            b[j] = p&1;
            p >>= 1;
            j++;
        }
        for(i=j-1;i>=0;i--)
        {
            if(b[i])
                res++;
            else
            {
                if(res&1)
                {
                    printf("%s\n",s1);
                    flag = false;
                    break;
                }
                else
                    res=0;
            }
        }
        if(flag)
        {
            if(strcmp(s1,"Karthik") is 0)
                printf("Suman\n");
            else
                printf("Karthik\n");
        }
        if(n%(x+1) is 0)
        {
            if(strcmp(s2,"Karthik") is 0)
                printf("Suman\n");
            else
                printf("Karthik\n");
        }
        else
        {
            printf("%s\n",s2);
        }
    }
    return 0;
}