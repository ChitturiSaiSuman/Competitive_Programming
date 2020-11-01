#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 1000000
int count[size]={0};
int ans[8][size];
void sieve()
{
    bool *prime;
    prime=(bool *)malloc(sizeof(bool)*size);
    for(int i=0;i<size;i++)
        prime[i]=true;
    prime[0]=prime[1]=false;
    for(int i=2;i<size;i++)
    {
        if(prime[i])
        {
            count[i]++;
            for(int j=2;j*i<size;j++)
            {
                count[i*j]++;
                prime[i*j]=false;
            }
        }
    }
    free(prime);
    for(int i=0;i<8;i++)
        ans[i][0]=0;
    for(int i=0;i<8;i++)
        for(int j=1;j<size;j++)
            if(count[j]==i)
                ans[i][j]=ans[i][j-1]+1;
            else
                ans[i][j]=ans[i][j-1];
}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);
        int answer;
        answer=ans[k][b]-ans[k][a];
        if(count[a]==k)
            answer++;
        printf("%d\n",answer);
    }
    return 0;
}