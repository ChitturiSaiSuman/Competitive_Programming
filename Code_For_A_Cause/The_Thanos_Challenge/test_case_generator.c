#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#define and &&
#define or ||
#define not !
#define is ==
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define size 1000
#define mod ((int)(1e9+7))
typedef long long int ll;
int solve(int x, int y, int n, char *s)
{
    int ans = INT_MAX;
    if(x==0 && y==0)
        ans = 0;
	for(int i=0;i<n;i++)
    {
        if(s[i]=='S')
            y--;
        else if(s[i]=='N')
            y++;
        else if(s[i]=='E')
            x++;
        else if(s[i]=='W')
            x--;
		if(abs(x)+abs(y)<=i+1)
        {
            ans = min(ans, i+1);
            break;
        }
	}
    return ans;
}
int main()
{
    FILE *input,*output;
    srand(time(0));
    char directions[]="NEWS";
    input = fopen("input.txt","w");
    output = fopen("output.txt","w");
    int t = size;
    fprintf(input,"%d\n",t);
    int count = 0;
    for(int test = 0; test<t;test++)
    {
        int x, y, length;
        if(test<650)
        {
            x = rand()%250 + 1;
            y = rand()%250 + 1;
            length = rand()%400 + 1;
        }
        else
        {
            x = rand()%size + 1;
            y = rand()%size + 1;
            length = rand()%size + 1;
        }
        char * M = (char *)malloc(sizeof(char)*(length+1));
        if(test < 500)
        {
            for(int i=0;i<length; i++)
                M[i]= directions[rand()%3+1];
        }
        else
        {
            for(int i=0;i<length;i++)
                M[i]= directions[rand()%4];
        }
        M[length] ='\0';
        fprintf(input,"%d %d %s\n",x,y,M);
        int answer = solve(x,y,length,M);
        if(answer == INT_MAX)
        {
            fprintf(output,"IMPOSSIBLE\n");
            count++;
        }
        else
            fprintf(output,"%d\n",answer);
        free(M);
    }
    fclose(input);
    fclose(output);
    printf("%d",count);
    return 0;
}