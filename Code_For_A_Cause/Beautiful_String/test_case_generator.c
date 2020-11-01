#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define max_length 100000
#define test_limit 1000
#define max_cost 1000
typedef long long int ll;
int solve(char s[], int length, int a, int b)// Costs: "0 to 1" -> a, "1 to 0" -> b
{
    int *prefix = (int *)malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
        prefix[i] = 0;
    int total_ones = 0;
    for(int i = 0; i < length; i++)
        total_ones += s[i]-'0';// To calculate number of ones in given binary String.
    int total_zeroes = length - total_ones;
    ll answer  =  (ll) ( min ( total_ones * b, total_zeroes * a) );//Initialising the answer with Maximum possible value.
    prefix[0] = s[0] - '0';
    for(int i = 1; i < length; i++)
        prefix[i] = prefix[i-1] + s[i] - '0';
    for(int i = 0; i < length; i++)
    {
        int ones_on_left = prefix[i];
        int zeroes_on_left = (i+1) - ones_on_left;
        int ones_on_right = total_ones - ones_on_left;
        int zeroes_on_right = total_zeroes - zeroes_on_left;
        ll temp_cost  =  ( zeroes_on_left * a + ones_on_right * b );//Some ones followed by some zeroes
        answer = min(answer , temp_cost);
        temp_cost = (ones_on_left * b + zeroes_on_right * a);//Some zeroes followed by some ones
        answer = min(answer , temp_cost);
    }
    free(prefix);
    return answer;
}
int main()
{
    srand(time(0));
    FILE *in,*out;
    char input[]="input00.txt";
    char output[]="output00.txt";
    int test_files=1;
    while(test_files--)
    {
        in = fopen(input,"w");
        out = fopen(output,"w");
        int t;
        t = test_limit;
        fprintf(in,"%d\n",t);
        while(t--)
        {
            int n,a,b;
            if(t<100)
                n = max_length;
            else
                n = rand()%(max_length/100)+1;
            a = rand()%max_cost+1;
            b = rand()%max_cost+1;
            fprintf(in,"%d %d %d\n",n,a,b);
            char s[max_length];
            if(t<50)
            {
                int value=rand()%2;
                for(int i=0;i<n;i++)
                    s[i]=value+'0';
                s[n]='\0';
            }
            else
            {
                for(int i=0;i<n;i++)
                    s[i]=rand()%2+'0';
                s[n]='\0';
            }
            fprintf(in,"%s\n",s);
            int answer = solve(s,n,a,b);
            fprintf(out,"%d\n",answer);
        }
        fclose(in);
        fclose(out);
        if(input[6]=='9')
        {
            input[6]='0';
            input[5]++;
            output[7]='0';
            output[6]++;
        }
        else
        {
            input[6]++;
            output[7]++;
        }       
    }
    return 0;
}