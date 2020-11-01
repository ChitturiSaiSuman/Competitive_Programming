#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    char s1[10004],s2[10004];
    scanf("%s",s1);
    scanf("%s",s2);
    int count_m=0;
    int count_r=0;
    for(int i=0;i<n;i++)
    {
        if(s2[i]=='m')
            count_m++;
        else
            count_r++;
    }
    int matched=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i]=='m' && count_m>0)
        {
            matched++;
            count_m--;
        }
        else if(s1[i]=='r' && count_r>0)
        {
            matched++;
            count_r--;
        }
        else
        {
            break;
        }
    }
    printf("%d",n-matched);
    return 0;
}