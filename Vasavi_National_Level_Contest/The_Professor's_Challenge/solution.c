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
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n;
        scanf("%d",&n);
        tuple list[size];
        for(int i=0;i<n;i++)
            scanf("%lld %lld",&list[i].x,&list[i].y);
        int ind = solve(list,n);
        printf("%lld %lld\n",list[ind].x,list[ind].y);
    }
    return 0;
}