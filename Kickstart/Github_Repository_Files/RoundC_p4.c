#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 200006
int main()
{
    int t;
    scanf("%d",&t);
    int test=0;
    while(t--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        int a[size];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        long long int ans=0;
        while (q--)
        {
            char ch;
            int x,y;
            char trash;
            scanf("%c %c %d %d",&trash,&ch,&x,&y);
            x-=1;
            if(ch=='U')
                a[x]=y;
            else
            {
                long long int temp=0;
                int c=0;
                for(int i=x;i<y;i++,c++)
                    temp+=pow(-1,c)*a[i]*(c+1);
                ans+=temp;
            }
        }
        test++;
        printf("Case #%d: %lld\n",test,ans);
    }
    return 0;
}