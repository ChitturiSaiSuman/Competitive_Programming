/*
Template by Sai Suman Chitturi.
TALK IS CHEAP. SHOW ME THE CODE.
Hackerrank: skynetasspyder
Codechef: suman_18733097
Codeforces: saisumanchitturi
Github: ChitturiSaiSuman
Hackerearth: chitturi7
SPOJ: Sai Suman Chitturi @out_of_bound
*/
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
#define newline printf("\n")
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define size 100005
#define mod 1000000007
typedef unsigned long long int ull;
typedef long long int ll;
int ascending(const void *a, const void *b){return ((*(int *)a-*(int *)b)>0?1:-1);}
int descending(const void *a, const void *b){return ((*(int *)a-*(int *)b)>0?-1:1);}
int LCS(char s1[], char s2[], int m, int n)
{
	int lcs[203][203];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 or j==0)
				lcs[i][j]=0;
			else if(s1[i]==s2[j])
				lcs[i][j] = lcs[i-1][j-1]+1;
			else
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	}
	return lcs[m][n];
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int test = 0; test<t;test++)
	{
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		char s1[203],s2[203];
		scanf("%s",s1);
		scanf("%s",s2);
		int ans = INT_MAX;
		if(LCS(s1,s2,n,m)>=k)
			printf("0");
		else
		{
			for(int i=0;i<n;i++)
			{
				for(char j='a';j<='z';j++)
				{
					char temp = s1[i];
					s1[i]=j;
					if(LCS(s1,s2,n,m)>=k)
						ans = min(ans,abs(j-temp));
					s1[i]=temp;
				}
			}
			printf("%d",ans);
		}
		newline;
	}
	return 0;
}