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
#define size (2*(1e6+1))
#define mod ((int)(1e9+7))
typedef long long int ll;
void solve()
{
    int n,q;
    scanf("%d %d",&n,&q);
    int a[1001];
    for(int i=0;i<n-1;i++)
        scanf("%d",&a[i]);
    int answer[1001];
    int query=0;
    for(query = 0; query<q;query++)
    {
        int entered_room;
        int last_room;
        scanf("%d %d",&entered_room,&last_room);
        int last_visited = entered_room;
        int ind1 = entered_room-2;
        int ind2 = entered_room-1;
        for(int visit =0; visit <last_room-1; visit++)
        {
            if(ind1>=0 and ind2<n)
            {
                if(a[ind1]<a[ind2])
                {
                    last_visited=ind1+1;
                    ind1--;
                }
                else
                {
                    ind2++;
                    last_visited=ind2+1;
                }
            }
            else if(ind1>=0)
            {
                last_visited=ind1+1;
                ind1--;
            }
            else if(ind2<n)
            {
                ind2++;
                last_visited=ind2+1;
            }
        }
        answer[query]=last_visited;
    }
    for(int i=0;i<query-1;i++)
        printf("%d ",answer[i]);
    printf("%d\n",answer[query-1]);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test = 0 ; test < t; test++)
    {
        printf("Case #%d: ",test+1);
        solve();
    }
    return 0;
}