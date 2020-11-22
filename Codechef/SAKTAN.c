#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long int ll;
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int m,n,q;
        scanf("%d %d %d",&m,&n,&q);
        int *row = (int *)malloc(sizeof(int)*m);
        int *col = (int *)malloc(sizeof(int)*n);
        for(int i=0;i<m;i++)
            row[i] = 0;
        for(int i=0;i<n;i++)
            col[i] = 0;
        for(int query = 0; query<q;query++)
        {
            int r,c;
            scanf("%d %d",&r,&c);
            row[r-1]++;
            col[c-1]++;
        }
        ll ans = 0;
        int odd1 = 0;
        int odd2 = 0;
        int even1 = 0;
        int even2 = 0;
        for(int i=0;i<m;i++)
            if(row[i]%2)
                odd1++;
            else
                even1++;
        for(int i=0;i<n;i++)
            if(col[i]%2)
                odd2++;
            else
                even2++;
        ans = ans + ((ll)(odd1))*((ll)(even2)) + ((ll)(odd2))*((ll)(even1));
        printf("%lld\n",ans);
        free(row);
        free(col);
    }
    return 0;
}