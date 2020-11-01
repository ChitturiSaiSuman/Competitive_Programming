#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 101
void solve(char s[],int n)
{
    if(n==1)
    {
        int f=s[0]-'0';
        for(int i=0;i<f;i++)
        printf("(");
        printf("%c",s[0]);
        for(int i=0;i<f;i++)
            printf(")");
    }
    else
    {
        int i;
        int f;
        int count1=0;
        int count2=0;
        f=s[0]-'0';
        for(i=0;i<f;i++)
            printf("(");
        printf("%c",s[0]);
        count1=f;
        for(i=1;i<n;i++)
        {
            int j;
            int diff=s[i]-s[i-1];
            if(diff<0)
            {
                for(j=0;j<(-1*diff);j++)
                {
                    printf(")");
                    count2++;
                }
            }
            else
            {
                for(j=0;j<diff;j++)
                {
                    printf("(");
                    count1++;
                }
            }
            printf("%c",s[i]);
        }
        //printf("Counts: %d %d\t",count1,count2);
        if(count1!=count2)
        {
            for(i=0;i<count1-count2;i++)
                printf(")");
        }
    }
    printf("\n");
}
int main()
{
    int t,n;
    char s[size];
    int i;
    int counter=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        n=strlen(s);
        printf("Case #%d: ",counter++);
        solve(s,n);
    }
    return 0;
}
