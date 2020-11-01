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
#define size ((int)(1e6+2))
#define mod ((int)(1e9+7))
typedef unsigned long long int ull;
typedef long long int ll;
int main()
{
	int t;
	scanf("%d",&t);
	int pat[103];
	for(int i=0;i<100;i++)
		pat[i]=i;
	for(int test = 0; test<t;test++)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		int max_value=min(m,n);
		for(int i=0;i<m;i++)
		{
			int ind=(i+1)%max_value+1;
			for(int j=0;j<n;j++)
			{
				printf("%d ",pat[ind]);
				ind=(ind+1)%(max_value+1);
				if(ind==0)
					ind=1;
			}
			printf("\n");
		}
	}
	return 0;
}