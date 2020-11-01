#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 1000000
int main()
{
    char input[]="input00.txt";
    FILE *fptr;
    int n;
    int t;
    int test=12;
    char trash;
    while(test--)
    {
        fptr=fopen(input,"r");
        fscanf(fptr,"%d",&t);
        if(t>size)
        {
            printf("Test Cases more!: %d\n",t);
            scanf("%c",&trash);
        }
        while(t--)
        {
            fscanf(fptr,"%d",&n);
            if(n>size)
            {
                printf("Number More!: %d\n",n);
                scanf("%c",&trash);
            }
        }
        if(input[6]=='9')
        {
            input[6]='0';
            input[5]++;
        }
        else
            input[6]++;
        fclose(fptr);
    }
    return 0;
}
