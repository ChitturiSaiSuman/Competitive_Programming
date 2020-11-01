#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define size 1005
typedef struct Job
{
    int start_time;
    int end_time;
    int pos;
    char ch;
}Job;
Job job[size];
int compare(const void *a, const void *b)
{
    Job j1,j2;
    j1=*(Job *)a;
    j2=*(Job *)b;
    if(j1.end_time!=j2.end_time)
        return j1.end_time-j2.end_time;
    return j1.start_time-j2.start_time;
}
int compare2(const void *a, const void *b)
{
    Job j1,j2;
    j1=*(Job *)a;
    j2=*(Job *)b;
    return j1.pos-j2.pos;
}
void solve(int n)
{
    int i;
    bool flag=true;
    int overlaps;
    i=0;
    int j;
    while(i<n-1)
    {
        if(job[i].end_time>job[i+1].start_time)
        {
            overlaps=0;
            j=i+1;
            while(j<n && job[i].end_time>job[j].start_time)
            {
                overlaps++;
                j++;
            }
            if(overlaps>=2)
            {
                flag=false;
                break;
            }
        }
        i++;
    }
    if(!flag)
        printf("IMPOSSIBLE\n");
    else
    {
        flag=false;
        bool another_job=false;
        for(i=0;i<n-1;i++)
        {
            if(job[i].end_time>job[i+1].start_time)
            {
                if(job[i].ch=='A')
                {
                    job[i].ch='C';
                    job[i+1].ch='J';
                }
                else
                {
                    if(job[i].ch=='J')
                        job[i+1].ch='C';
                    else
                        job[i+1].ch='J';
                }
                
            }
            else if(job[i].ch=='A')
            {
                job[i].ch='C';
            }
            else
            {
                job[i+1].ch='C';
            }
        }
        if(job[i].ch=='A')
        {
            if(job[i-1].end_time>job[i].start_time)
            {
                if(job[i-1].ch=='C')
                    job[i].ch='J';
                else
                {
                    job[i].ch='C';
                }
            }
            else
            {
                job[i].ch=job[i-1].ch;
            }
            
        }
        qsort(job,n,sizeof(Job),compare2);
        for(i=0;i<n;i++)
            printf("%c",job[i].ch);
        printf("\n");
    }
}
int main()
{
    int t,n,i;
    scanf("%d",&t);
    int counter=1;
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&job[i].start_time,&job[i].end_time);
            job[i].pos=i;
            job[i].ch='A';
        }
        qsort(job,n,sizeof(Job),compare);
        printf("Case #%d: ",counter++);
        solve(n);
    }
    return 0;
}