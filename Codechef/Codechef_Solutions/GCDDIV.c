#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}
void solve(int *a, int n, int k)
{
    for(int i=0;i<n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            while(a[i]%j==0)
                a[i]/=j;
        }
    }
    int g = a[0];
    for(int i=1;i<n;i++)
        g=gcd(g,a[i]);
    printf(g==1?"YES\n":"NO\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        int *a;
        a=(int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        solve(a,n,k);
        free(a);
    }
    return 0;
}