#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<assert.h>
#define and &&
#define or ||
#define not !
#define is ==
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define size ((int)(1e5+2))
#define mod ((int)(1e9+7))
typedef unsigned long long int ull;
typedef long long int ll;
int main()
{
	int t;
	scanf("%d",&t);
	for(int test = 0; test<t;test++)
	{
		int n;
		scanf("%d",&n);
        char s[size];
        scanf("%s",s);
        ll ans=0;
        int *prefix = (int *)malloc(sizeof(int)*n);
        prefix[0]=s[0]-'0';
        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+s[i]-'0';
        int i=0;
        while(i<n)
        {
            int temp=prefix[i];
            if(i==0 && prefix[i]==1)
                ans++;
            int j=i+1;
            while(i<n and j<n and prefix[j]-prefix[i]!=(j+1-i))
                j++;
            if(j<n)
                ans++;
            i=j;
        }
        printf("%lld\n",ans);
	}
	return 0;
}