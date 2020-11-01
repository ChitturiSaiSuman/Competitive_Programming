#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define test 1000000
#define size 10000000
int main()
{
    FILE *input;
    input=fopen("input.txt","w");
    srand(time(0));
    fprintf(input,"%d\n",test);
    for(int t=0;t<test;t++)
    {
        int n;
        n=rand()%size+1;
        fprintf(input,"%d\n",n);
    }
    return 0;
}