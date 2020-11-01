#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<limits.h>
#include<time.h>
#define or ||
#define and &&
#define not !
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define size 
#define mod 1000000000
#define test_limit 10000
typedef long long int ll;
int pair[]={0,1,2,3,4,5,6,7,8,9};
FILE *status;
void update(int a, int b)//Updates the positions of swapped digits
{
    int i;
    for(i=0;i<10;i++)
        if(pair[i]==a)
            break;
    int ind1=i;
    for(i=0;i<10;i++)
        if(pair[i]==b)
            break;
    int ind2=i;
    int value1=pair[ind1];
    int value2=pair[ind2];
    pair[ind1]=(pair[ind1]+pair[ind2])-(pair[ind2]=pair[ind1]);//one liner for swap
    if(pair[ind1]!=value2 or pair[ind2]!=value1)
        fprintf(status,"Swap Failed\n");
}
ll reverse(ll n)//Working code for reversing a number
{
    ll s=0;
    while(n>0)
    {
        s=s*10+n%10;
        n/=10;
    }
    return s;
}
ll decode(ll n)//decodes the number given
{
    ll s=0;
    while(n>0)
    {
        int digit=n%10;
        int i;
        for( i=0;i<10;i++)
            if(pair[i]==digit)
                break;
        s=s*10+i;
        n/=10;
    }
    s=reverse(s);
    return s;
}
ll solve(ll A, ll B, char operator)//Calculates the Result of operation
{
    ll result;
    A=decode(A);
    B=decode(B);
    switch(operator)
    {
        case '+': result=A+B;
                    break;
        case '-': result=A-B;
                    break;
        case '*': result=A*B;
                    break;
        case '/': result=A/B;
                    break;
        default: fprintf(status,"Operation not supported\n");
                    break;
    }
    return result;
}
int main()
{
    srand(time(0));
    FILE *input,*output;
    char in[]="input00.txt";
    char out[]="output00.txt";
    status=fopen("status.txt","w");
    int number_of_test_files=50;
    char sign[][4]={"ADD","SUB","MUL","DIV"};
    while(number_of_test_files--)
    {
        input=fopen(in,"w");
        output=fopen(out,"w");
        int number_of_swap_operations=rand()%test_limit+1;
        fprintf(input,"%d\n",number_of_swap_operations);
        while(number_of_swap_operations--)
        {
            int a,b;
            a=rand()%10;
            b=rand()%10;
            while(b==a)
                b=rand()%10;
            fprintf(input,"%d %d\n",a,b);
        }
        ll A,B;
        A=rand()%mod+1;
        B=rand()%mod+1;
        char operator=sign[rand()%4];
        fprintf(input,"%lld %lld %c",A,B,operator);
        ll ans=solve(A,B,operator);
        if(ans>mod)
            fprintf(status,"Exclusive Constraints met in %s\n",in);
        else if(ans==0)
            fprintf(status,"0 obtained in %s\n",in);
        else if(ans<0)
            fprintf(status,"Negative obtained in %s\n",in);
        fprintf(output,"%lld",ans);
        fclose(input);
        fclose(output);
        if(in[6]=='9')
        {
            in[5]++;
            in[6]='0';
            out[6]++;
            out[7]='0';
        }
        else
        {
            in[6]++;
            out[7]++;
        }
    }
    fclose(status);
    return 0;
}