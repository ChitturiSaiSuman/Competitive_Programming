#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>
#include<time.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define or ||
#define and &&
#define not !
#define size 100001 // Maximum possible length of the string
#define mod 
typedef long long int ll;
void working_solution()
{
    srand(time(0));
    FILE *input;
    input=fopen("input.txt","w");
    FILE *output=fopen("output.txt","w");
    int t = rand()%1000+1;
    fprintf(input,"%d\n",t);
    while(t--)
    {
        int n=rand()%(size-1)+1;
        int a,b;
        a = rand()%1000+1;
        b = rand() % 1000 +1;
        fprintf(input,"%d %d %d\n",n,a,b);
        char s[size];
        for(int i=0;i<n;i++)
            s[i]=rand()%2+'0';
        s[n]='\0';
        fprintf(input,"%s\n",s);
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
        fprintf(output,"%d\n",ans);
        free(prefix);
    }
    fclose(input);
    fclose(output);
}
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
    return answer;
    free(prefix);
}
void editorialist_solution()
{
    int t;
    FILE *input,*output;
    input = fopen("input.txt","r");
    output = fopen("output.txt","r");
    fscanf(input,"%d",&t);
    for(int test = 0; test < t; test++)
    {
        int n,a,b;
        fscanf(input,"%d %d %d",&n,&a,&b);
        a=b=1;
        char s[size];
        fscanf(input,"%s",s);
        int myanswer = solve(s,n,a,b);
        int actual_answer;
        fscanf(output,"%d",&actual_answer);
        if(actual_answer!=myanswer)
            printf("%d test case failed\n",test);
    }
    fclose(input);
    fclose(output);
}
int main()
{
    working_solution();
    editorialist_solution();
    return 0;
}