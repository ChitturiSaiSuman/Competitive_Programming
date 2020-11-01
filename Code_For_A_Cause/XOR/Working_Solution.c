#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 1000000
int main()
{
    int length,i,j;
    int num;
    int mod;
    char string[size];
    scanf("%s",string);
    length=strlen(string);
    printf("%d ",length);
    if(length>1)
    num=(string[length-1]-'0')+10*(string[length-2]-'0');
    else
    num=(string[length-1]-'0');
    printf("%d ",num);
    mod=num%4;
    if(mod==0)
        printf("%s",string);
    else if(mod==1)
        printf("1");
    else if(mod==2)
    {
        string[length-1]++;
        printf("%s",string);
    }
    else
        printf("0");
    return 0;
}