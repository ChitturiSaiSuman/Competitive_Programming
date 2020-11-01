#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
#define and &&
#define or ||
#define not !
#define is ==
#define newline printf("\n")
#define FOR(x,n) for(int x=0;x<n;x++)
#define For(x,n) FOR(x,n)
#define caseprint printf("Case #%d: ",test+1);
#define inverse(a) power(a,mod-2,mod);
const int size = 100003; // 10**5+3
const int mod = 1000000007; // 10**9+7
typedef unsigned long long int ull;
typedef long long int ll;
static inline ll max(ll a, ll b) {return (a>b?a:b);}
static inline ll min(ll a, ll b) {return (a<b?a:b);}
static inline ll mul(ll a, ll b) {return ((a%mod*b%mod)%mod);}
static inline ll add(ll a, ll b) {return ((a%mod+b%mod)%mod);}
static inline ll sub(ll a, ll b) {return ((a%mod-b%mod)+mod)%mod;}
static inline int sum_of_digits(ll n) { return n>0?n%10+sum_of_digits(n/10):0;}
static inline int number_of_digits(ll n) { return n>0?1+number_of_digits(n/10):0;}
int ascending (const void *a, const void *b){return ((*(ll *)a-*(ll *)b)>0?1:-1);}
int descending(const void *a, const void *b){return ((*(ll *)a-*(ll *)b)>0?-1:1);}
ll power(ll x, ll y, ll p){
	x=x%p;if(x<2) return x; ll result=1;
	for(;y>0;y/=2,x=mul(x,x)){
		if(y&1)result=mul(result,x);
	}
	return result;
}

int main()
{
	int t;
	t=1;
	For(test,t)
	{
		int n;
		const int dim = 32;
		scanf("%d",&n);
		int *a = (int *)malloc(sizeof(int)*n);
		FOR(i,n)
			scanf("%d",&a[i]);
		// ll **bits;
		// bits = (ll **)malloc(sizeof(ll *)*n);
		// FOR(i,n)
		// 	bits[i] = (ll *)malloc(sizeof(ll)*dim);
		ll **vals = (ll **)malloc(sizeof(ll *)*n);
		FOR(i,n)
			vals[i] = (ll *)malloc(sizeof(ll)*dim);
		ll **prefix = (ll **)malloc(sizeof(ll *)*n);
		FOR(i,n)
			prefix[i] = (ll *)malloc(sizeof(ll)*dim);
		FOR(i,n)
		{
			int temp = a[i];
			ll value_so_far = 0;
			FOR(j,dim)
			{
				if(!(temp&1))
					vals[i][dim-j-1] = (1LL<<j)-value_so_far;
				else
					vals[i][dim-j-1] = 0;
				value_so_far += (1LL<<j)*(temp&1);
				temp/=2;
			}
		}
		FOR(i,dim)
			prefix[0][i] = vals[0][i];
		FOR(i,n-1)
			FOR(j,dim)
				prefix[i+1][j] = prefix[i][j] + vals[i+1][j];
		// FOR(i,n)
		// {
		// 	FOR(j,dim)
		// 		printf("%lld ",vals[i][j]);
		// 	newline;
		// }
		int q;
		scanf("%d",&q);
		FOR(Q,q)
		{
			int l,r;
			scanf("%d %d",&l,&r);
			--l;
			--r;
			ll ans = LLONG_MAX;
			FOR(i,dim)
			{
				ll temp = vals[l][i]+prefix[r][i]-prefix[l][i];
				ans = min(ans,temp);
			}
			printf("%lld\n",ans);
		}
		free(a);
		// FOR(i,n)
		// 	free(bits[i]);
		// free(bits);
		FOR(i,n)
			free(vals[i]);
		free(vals);
		FOR(i,n)
			free(prefix[i]);
		free(prefix);
	}
	return 0;
}
