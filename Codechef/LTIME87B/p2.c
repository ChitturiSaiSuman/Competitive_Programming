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
typedef struct pair
{
	int ind;
	int val;
}pair;
int compare(const void *a, const void *b)
{
	pair *p1,*p2;
	p1 = (pair *)a;
	p2 = (pair *)b;
	return p2->val>p1->val?1:-1;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int test = 0; test<t;test++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int initial[505];
		for(int i=0;i<n;i++)
			scanf("%d",&initial[i]);
		int changes[505][505];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&changes[i][j]);
		int ratings[505][505];
		for(int i=0;i<n;i++)
			ratings[i][0]=initial[i]+changes[i][0];
		for(int i=0;i<n;i++)
			for(int j=1;j<m;j++)
				ratings[i][j]=ratings[i][j-1]+changes[i][j];
		int rankings[505][505];
		for(int i=0;i<m;i++)
		{
			pair a[505];
			for(int j=0;j<n;j++)
			{
				a[j].val=ratings[j][i];
				a[j].ind=j;
			}
			qsort(a,n,sizeof(pair),compare);
			int rank = 1;
			for(int j=0;j<n;j++)
			{
				int temp = a[j].val;
				int count = 0;
				while (j<n and a[j].val==temp)
				{
					count++;
					rankings[a[j].ind][i]=rank;
					j++;
				}
				j--;
				rank+=count;
			}
		}
		int table[505][505];
		for(int i=0;i<505;i++)
			for(int j=0;j<505;j++)
				table[i][j]=0;
		for(int i=0;i<n;i++)
		{
			int ind1 = -1;
			int ind2 = -1;
			int max_rating = INT_MIN;
			int min_ranking = INT_MAX;
			for(int j=0;j<m;j++)
			{
				if(ratings[i][j]>max_rating)
				{
					max_rating=ratings[i][j];
					ind1=j;
				}
				if(rankings[i][j]<min_ranking)
				{
					min_ranking = rankings[i][j];
					ind2 = j;
				}
			}
			table[i][ind1]++;
			table[i][ind2]++;
		}
		int ans= 0;
		for(int i=0;i<n;i++)
		{
			int flag=1;
			for(int j=0;j<m;j++)
			{
				if(table[i][j]==2)
				{
					flag=0;
					break;
				}
			}
			ans+=flag;
		}
		printf("%d\n",ans);
	}
	return 0;
}