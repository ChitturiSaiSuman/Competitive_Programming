#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int getParent(int *parent, int n, int x)
{
    while(parent[x]!=x)
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void weightedUnion(int *weights, int *parent, int n, int x, int y)
{
    int rootA = getParent(parent,n,x);
    int rootB = getParent(parent,n,y);
    if(rootA==rootB)
    {
        printf("Invalid query!\n");
        return;
    }
    else
    {
        if(weights[rootA]<weights[rootB])
        {
            parent[rootA] = rootB;
        }
        else
        {
            parent[rootB] = rootA;
        }
    }
    
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n;
        scanf("%d",&n);
        n+=5;
        int *weights = (int *)malloc(sizeof(int)*n);
        int *parent = (int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            parent[i] = i;
        n-=5;
        for(int i=1;i<n+1;i++)
            scanf("%d",&weights[i]);
        n+=5;
        // for(int i=0;i<n;i++)
        //     printf("%d ",weights[i]);
        // printf("\n");
        int q;
        scanf("%d",&q);
        for(int query = 0; query < q; query++)
        {
            int type;
            scanf("%d",&type);
            if(type)
            {
                int x;
                scanf("%d",&x);
                printf("%d\n",getParent(parent,n,x));
            }
            else
            {
                int x,y;
                scanf("%d %d",&x,&y);
                weightedUnion(weights,parent,n,x,y);
            }
        }
        free(parent);
        free(weights);
    }
    return 0;
}