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
int main()
{
    int t;
    scanf("%d",&t);
    assert(t>0 and t<=size);
    for(int test = 0; test < t; test ++)
    {
        int x, y;
        char s[size];
        scanf("%d %d %s",&x,&y,s);
        int n = strlen(s);
        assert(n>0 and n<=size);
        assert(x>=0 and x<=size);
        assert(y>=0 and y<=size);
        int ans = INT_MAX;
        if( x is 0 and y is 0)
            ans = 0;
        else
        {
            for(int i=0;i<n; i++)
            {
                if(s[i]=='S')
                    y--;
                else if(s[i]=='N')
                    y++;
                else if(s[i]=='E')
                    x++;
                else
                    x--;
                if(abs(x)+abs(y) <= i+1)
                {
                    ans = min(ans,i+1);
                    break;
                }
            }
        }
        if(ans is INT_MAX)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}