#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int main()
{
    int a[20][20];
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            scanf("%d",&a[i][j]);
    int vert[20][20];
    int hori[20][20];
    int diagonal1[20][20];
    int diagonal2[20][20];
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            vert[i][j]=hori[i][j]=diagonal1[i][j]=diagonal2[i][j]=0;
    for(int i=0;i<17;i++)
        for(int j=0;j<20;j++)
            vert[i][j]=a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
    for(int i=0;i<20;i++)
        for(int j=0;j<17;j++)
            hori[i][j]=a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
    for(int i=0;i<17;i++)
        for(int j=0;j<17;j++)
            diagonal1[i][j]=a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
    for(int i=0;i<17;i++)
        for(int j=3;j<20;j++)
            diagonal2[i][j]=a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3];
    int answer=0;
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
        {
            answer=max(answer,vert[i][j]);
            answer=max(answer,hori[i][j]);
            answer=max(answer,diagonal1[i][j]);
            answer=max(answer,diagonal2[i][j]);
        }
    printf("%d",answer);
    return 0;
}