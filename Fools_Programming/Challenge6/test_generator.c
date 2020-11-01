#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define size 1000000000000000000
int count_set(unsigned long long int a)
{
    int c=0;
    while(a>0)
    {
        c+=a%2;
        a/=2;
    }
    return c;
}
int main()
{
    int test=20;
    srand(time(0));
    FILE *input,*output;
    char in[]="input00.txt";
    char out[]="output00.txt";
    int t;
    int c;
    unsigned long long int n;
    while(test--)
    {
        input=fopen(in,"w");
        output=fopen(out,"w");
        t=(rand()%1000000)+1;
        fprintf(input,"%d\n",t);
        while(t--)
        {
            n=(rand()%size)+1;
            fprintf(input,"%llu\n",n);
            c=count_set(n);
            fprintf(output,"%d\n",c);
        }
        if(in[6]=='9')
        {
            in[6]='0';
            in[5]++;
            out[7]='0';
            out[6]++;
        }
        else
        {
            in[6]++;
            out[7]++;
        }
        fclose(input);
        fclose(output);
    }
}
