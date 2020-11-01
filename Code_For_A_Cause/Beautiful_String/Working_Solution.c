#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[1004];
        scanf("%s",s);
        int n=strlen(s);
        int *prefix;
        prefix=(int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            prefix[i]=0;
        prefix[0]=s[0]-'0';
        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+s[i]-'0';
        int count=0;
        for(int i=0;i<n;i++)
            count+=s[i]-'0';
        int ans=count;
        for(int i=0;i<n;i++)
        {
            int number_of_ones_changed_to_zero_on_left=prefix[i];
            int number_of_zeroes_changed_to_one_on_right=(n-count)-(i+1-prefix[i]);
            int temp=number_of_ones_changed_to_zero_on_left+number_of_zeroes_changed_to_one_on_right;
            if(temp<ans)
                ans=temp;
        }
        for(int i=0;i<n;i++)
        {
            int number_of_zeroes_changed_to_one_on_left=(i+1)-prefix[i];
            int number_of_ones_changed_to_zero_on_right=(count-prefix[i]);
            int temp=number_of_ones_changed_to_zero_on_right+number_of_zeroes_changed_to_one_on_left;
            if(temp<ans)
                ans=temp;
        }
        printf("%d\n",ans);
        free(prefix);
    }
    return 0;
}