#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<limits.h>
#define size 10000007
int a[size]={0};
int num;
bool *prime;
int count[size];
bool express[size];
void sieve()
{
    prime=(bool*)malloc(sizeof(bool)*size);
    for(int i=0;i<size;i++)
        prime[i]=true;
    prime[0]=prime[1]=false;
    for(int i=2;i*i<size;i++)
        if(prime[i])
            for(int j=i*i;j<size;j+=i)
                prime[j]=false;
    int j;
    j=0;
    for(int i=0;i<size;i++)
        if(prime[i])
            a[j++]=i;
    num=j;
    free(prime);
}
void calculate()
{
    for(int i=0;i<size;i++)
        express[i]=false;
    int i,j,k;
    i=j=k=0;
    while(a[i]*a[i]<size)
    {
        unsigned long long int value1=a[i]*a[i];
        j=0;
        while(value1+(a[j]*a[j]*a[j])<size)
        {
            unsigned long long int value2=value1+(a[j]*a[j]*a[j]);
            k=0;
            while(value2+(a[k]*a[k]*a[k]*a[k])<size)
            {
                unsigned long long int value3=value2+(a[k]*a[k]*a[k]*a[k]);
                express[value3]=true;
                k+=1;
            }
            j+=1;
        }
        i+=1;
    }
    count[0]=0;
    for(i=1;i<size;i++)
        count[i]=count[i-1]+express[i];    
}
int main()
{
    sieve();
    calculate();
    int t;
    scanf("%d",&t);
    int n;
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",count[n]);
    }
    return 0;
}