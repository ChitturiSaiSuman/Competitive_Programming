#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
bool is_perfect_square(double n)
{
    if(n<0)
        n=-n;
    double root=sqrt(n);
    return ((root-floor(root))==0);
}
int solve(int d, int p)
{
    if(d<0)
        return 0;
    else if(d==0)
    {
        if(is_perfect_square(p))
            return 2;
        else
            return 0;
    }
    else
    {
        if(p==0)
            return 2;
        else if(p<0)
        {
            int count=0;
            for(int i=1;i<=sqrt(p);i++)
            {
                if(p%i==0)
                {
                        
                }
            }
        }
    }
    
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int p,d;
        scanf("%d %d",&d,&p);
        printf("%d\n",solve(d,p));
    }
    return 0;
}