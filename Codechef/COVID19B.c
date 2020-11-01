#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int v[10];
        for(int i=0;i<n;i++)
            scanf("%d",&v[i]);
        int position[10];
        int min_ans = INT_MAX;
        int max_ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                position[j]=j+1;
            bool infected[20];
            for(int j=0;j<n;j++)
                infected[j]=false;
            infected[i]=true;
            for(int time = 0; time<=100;time++)
            {
                for(int j=0;j<n;j++)
                    position[j]+=time*v[j];
                for(int iter = 0; iter < n; iter++)
                {
                    for(int i1=0;i1<n;i1++)
                        for(int i2=i1+1;i2<n;i2++)
                            if(position[i1]>=position[i2] && (infected[i1]||infected[i2]))
                                infected[i1]=infected[i2]=true;
                }
            }
            int infected_count = 0;
            for(int j=0;j<n;j++)
                infected_count+=infected[j]?1:0;
            if(infected_count<min_ans)
                min_ans = infected_count;
            if(infected_count>max_ans)
                max_ans = infected_count;
        }
        printf("%d %d\n",min_ans,max_ans);
    }
    return 0;
}