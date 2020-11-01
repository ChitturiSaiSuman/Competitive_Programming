#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>
#define size 100000
int main()
{
    srand(time(0));
    FILE *input,*output;
    char in[]="input00.txt";
    char out[]="output00.txt";
    int t,h,v1,v2,test;
    float t1,t2;
    float s,time;
    test=10;
    while(test--)
    {
        input=fopen(in,"w");
        output=fopen(out,"w");
        t=(rand()%size)+1;
        fprintf(input,"%d\n",t);
        while(t--)
        {
            v1=(rand()%size)+1;
            v2=(rand()%size)+1;
            h=(rand()%size)+1;
            fprintf(input,"%d %d %d\n",v1,v2,h);
            if(v1==v2 && h!=0)
            {
                fprintf(output,"%d\n",-1);
                continue;
            }
            time=((float)h/(v2-v1));
            t1=(float)v1/10;
            t2=(float)v2/10;
            if(time>t1 || time>t2)
            {
                fprintf(output,"%d",-1);
                continue;
            }
            if(time>0)
            {
                s=(float)(v2*time)-(float)(10)*time*time/2;
                if(s<0) s=s*-1;
            }
            else
            {
                time=-1;
                s=-1;
            }
            if((int)s!=-1)
                fprintf(output,"%0.2f %0.2f\n",time,s);
        else
            fprintf(output,"%d\n",-1);
        }
        if(in[6]=='9')
        {
            in[6]='0';
            in[5]++;
            out[6]++;
            out[7]='0';
        }
        else
        {
            in[6]++;
            out[7]++;
        }
        fclose(input);
        fclose(output);
    }
    return 0;
}
