#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#include<limits.h>
#include<assert.h>
#include<math.h>
#define or ||
#define and &&
#define not !
#define add(a,b) ((a%mod+b%mod)%mod)
#define sub(a,b) add(a%mod-b%mod,mod)
#define mul(a,b) ((a%mod*b%mod)%mod)
#define size 100000
typedef long long int ll;
typedef struct tuple
{
    ll x;
    ll y;
    ll range;
}tuple;
int solve(tuple list[], int n)
{
    int ind = 0;
    ll sum_x = 0;
    ll sum_y = 0;
    ll sum_x_square = 0;
    ll sum_y_square = 0;
    for(int i=0;i<n;i++)
    {
        sum_x+=list[i].x;
        sum_y+=list[i].y;
        sum_x_square+=((ll)(list[i].x*list[i].x));
        sum_y_square+=((ll)(list[i].y*list[i].y));
    }
    for(int i=0;i<n;i++)
    {
        list[i].range = ((ll)((n-1)*(list[i].x*list[i].x)));
        list[i].range +=((ll)((n-1)*(list[i].y*list[i].y)));
        list[i].range -=((ll)(2*list[i].x*(sum_x-list[i].x)));
        list[i].range -=((ll)(2*list[i].y*(sum_y-list[i].y)));
        list[i].range +=((ll)(sum_x_square-list[i].x*list[i].x));
        list[i].range +=((ll)(sum_y_square-list[i].y*list[i].y));
        if(list[i].range<list[ind].range)
            ind=i;
    }
    return ind;
}
int main()
{
    srand(time(0));
    int number_of_test_files = 9;
    char input[]="input00.txt";
    char output[]="output00.txt";
    FILE *in,*out;
    tuple list[size];
    for(int file = 0; file<number_of_test_files/3;file++)
    {
        in = fopen(input,"w");
        out = fopen(output,"w");
        int t = rand()%10+1;
        assert(t>0 and t<11);
        fprintf(in,"%d\n",t);
        for(int test=0;test<t;test++)
        {
            int n = rand()%size+1;
            assert(n>0 and n<100001);
            fprintf(in,"%d\n",n);
            for(int i=0;i<n;i++)
            {
                list[i].x = (rand()%(size*10+1))*(pow(-1,rand()));
                list[i].y = (rand()%(size*10+1))*(pow(-1,rand()));
                assert(-1000000<=list[i].x and list[i].x<=1000000);
                assert(-1000000<=list[i].y and list[i].y<=1000000);
                fprintf(in,"%lld %lld\n",list[i].x,list[i].y);
            }
            int ind = solve(list,n);
            fprintf(out,"%lld %lld\n",list[ind].x,list[ind].y);
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
    for(int file = 0; file<number_of_test_files/3;file++)
    {
        in = fopen(input,"w");
        out = fopen(output,"w");
        int t = 10;
        assert(t>0 and t<11);
        fprintf(in,"%d\n",t);
        for(int test=0;test<t;test++)
        {
            int n = rand()%(size/10)+1;
            assert(n>0 and n<100001);
            fprintf(in,"%d\n",n);
            for(int i=0;i<n;i++)
            {
                list[i].x = (rand()%(size*10+1))*(pow(-1,rand()));
                list[i].y = (rand()%(size*10+1))*(pow(-1,rand()));
                assert(-1000000<=list[i].x and list[i].x<=1000000);
                assert(-1000000<=list[i].y and list[i].y<=1000000);
                fprintf(in,"%lld %lld\n",list[i].x,list[i].y);
            }
            int ind = solve(list,n);
            fprintf(out,"%lld %lld\n",list[ind].x,list[ind].y);
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
    for(int file = 0; file<number_of_test_files/3;file++)
    {
        in = fopen(input,"w");
        out = fopen(output,"w");
        int t = 10;
        assert(t>0 and t<11);
        fprintf(in,"%d\n",t);
        for(int test=0;test<t;test++)
        {
            int n = size;
            assert(n>0 and n<100001);
            fprintf(in,"%d\n",n);
            for(int i=0;i<n;i++)
            {
                list[i].x = (rand()%(size*10+1))*(pow(-1,rand()));
                list[i].y = (rand()%(size*10+1))*(pow(-1,rand()));
                assert(-1000000<=list[i].x and list[i].x<=1000000);
                assert(-1000000<=list[i].y and list[i].y<=1000000);
                fprintf(in,"%lld %lld\n",list[i].x,list[i].y);
            }
            int ind = solve(list,n);
            fprintf(out,"%lld %lld\n",list[ind].x,list[ind].y);
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