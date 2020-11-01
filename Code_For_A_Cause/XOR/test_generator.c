#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<time.h>
#include<assert.h>
#include<stdbool.h>
#define and &&
#define or ||
#define not !
#define is ==
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define mod ((int)(1e9+7))
#define size ((int)(1e6))
typedef long long int ll;
void solve(char string[], int length,FILE *fptr)
{
    int num,  m;
    if(length>1)
        num=(string[length-1]-'0')+10*(string[length-2]-'0');
    else
        num=(string[length-1]-'0');
    m=num%4;
    if(m==0)
        fprintf(fptr,"%s\n",string);
    else if(m==1)
        fprintf(fptr,"1\n");
    else if(m==2)
    {
        string[length-1]++;
        fprintf(fptr,"%s\n",string);
    }
    else
        fprintf(fptr,"0\n");
}
void subtask0()
{
    FILE *input,*output;
    input = fopen("input01.txt","w");
    output = fopen("output01.txt","w");
    int test_limit = 100000;
    int max_string_length = 18;
    fprintf(input,"%d\n",test_limit);
    for(int test = 0; test<test_limit;test++)
    {
        char s[19];
        int length = rand()%max_string_length+1;
        s[0] = rand()%9+1+'0';
        for(int i=1;i<length;i++)
            s[i]=rand()%10+'0';
        s[length]='\0';
        fprintf(input,"%s\n",s);
        solve(s,length,output);
    }
    fclose(input);
    fclose(output);
}
void subtask1()
{
    FILE *input,*output;
    input = fopen("input02.txt","w");
    output = fopen("output02.txt","w");
    int test_limit = 50;
    int max_string_length = ((int)(1e6));
    fprintf(input,"%d\n",test_limit);
    for(int test = 0; test<test_limit;test++)
    {
        char s[max_string_length+1];
        int length = rand()%max_string_length+1;
        s[0] = rand()%9+1+'0';
        for(int i=1;i<length;i++)
            s[i]=rand()%10+'0';
        s[length]='\0';
        fprintf(input,"%s\n",s);
        solve(s,length,output);
    }
    fclose(input);
    fclose(output);
}
int main()
{
    subtask0();
    subtask1();
    return 0;
}