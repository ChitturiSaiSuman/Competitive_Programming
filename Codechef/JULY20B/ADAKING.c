#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int k;
        scanf("%d",&k);
        int n=8;
        k--;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    printf("O");
                else if(k>0)
                {
                    printf(".");
                    k--;
                }
                else
                {
                    printf("X");
                }
            }
            printf("\n");
        }
        printf("\n");        
    }
    return 0;
}