#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define size 100005
#define mod 1000000007
typedef unsigned long long int llt;
int count[size]={0};
void factorise(int n)
{
    if(n%2==0)
    {
        count[2]++;
        while(n%2==0)
            n/=2;
    }
    int i;
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
        {
            count[i]++;
            while(n%i==0)
                n/=i;
        }
    }
    if(n>2)
        count[n]++;
}
int main()
{
    int n;
    int i;
    scanf("%d",&n);
    int max=1;
    int temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        factorise(temp);
    }
    for(i=0;i<size;i++)
    {
        if(count[i]>max)
            max=count[i];
    }
    printf("%d",max);
}
