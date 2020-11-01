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
const int size = 1000003; // 10**6+3
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
	scanf("%d",&t);
	For(test,t)
	{
		int n,k,l;
		scanf("%d %d %d",&n,&k,&l);
		int temp;
		if(n%k==0)
			temp=n/k;
		else
		{
			temp=n/k;
			temp++;
		}
		if(temp>l)
			printf("-1");
		else if(k==1)
		    printf("-1");
		else
		{
			int c=1;
			FOR(i,n)
			{
				printf("%d ",c);
				c=(c+1)%k;
				if(c==0)
					c=k;
			}
		}
		newline;
	}
	return 0;
}
