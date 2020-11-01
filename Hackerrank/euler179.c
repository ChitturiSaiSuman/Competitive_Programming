#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define maxn  10000001
int cnt[maxn];
int  ans[maxn];

int main()
{
    //freopen("input.txt", "r", stdin);
    FILE *input,*output;
    input=fopen("input.txt","r");
    output=fopen("output.txt","w");
    for(int i = 1; i < maxn; i++)
        for(int j = i; j < maxn; j += i)
            cnt[j]++;
    for(int i = 1; i < maxn; i++)
        ans[i] = ans[i - 1] + (cnt[i] == cnt[i - 1]);
    int t;
    fscanf(input,"%d",&t);
    while(t--)
    {
        int n;
        fscanf(input,"%d",&n);
        fprintf(output,"%d\n",ans[n]);
    }
    fclose(input);
    fclose(output);
}