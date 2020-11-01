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
#define size 1000006
bool prime[size];
int count[size];
bool flag[size];
void sieve()
{
    int i,j;
    for(i=0;i<size;i++)
    {
        prime[i]=true;
        count[i]=0;
    }
    prime[0]=prime[1]=false;
    for(i=2;i*i<size;i++)
        if(prime[i])
            for(j=i*i;j<size;j+=i)
                prime[j]=false;
    for(i=2;i<size;i++)
        if(prime[i])
            count[i]=count[i-1]+1;
        else
            count[i]=count[i-1];
}
void myfun(int n)
{
    int i;
    for(i=1;i<size;i++)
        flag[i]=false;


}
int main()
{
    int t,n;
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        myfun(n);
    }
    return 0;
}
