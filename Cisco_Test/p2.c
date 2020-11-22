/*
Template by Sai Suman Chitturi.
I don't care at all. I am lost.
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
#define FOR(x,n) for(int x=0;x<n;x++)
#define For(x,n) FOR(x,n)
#define caseprint printf("Case #%d: ",test+1);
const int size = 1000003; // 10**6+3
const int mod = 1000000007; // 10**9+7
typedef unsigned long long int ull;
typedef long long int ll;
static inline ll max(ll a, ll b) {return (a>b?a:b);}
static inline ll min(ll a, ll b) {return (a<b?a:b);}
static inline ll mul(ll a, ll b) {return ((a%mod*b%mod)%mod);}
static inline ll add(ll a, ll b) {return ((a%mod+b%mod)%mod);}
static inline ll sub(ll a, ll b) {return ((a%mod-b%mod)+mod)%mod;}
static inline ll inverse(ll a) {return power(a,mod-2,mod);}
int ascending(const void *a, const void *b){return ((*(ll *)a-*(ll *)b)>0?1:-1);}
int descending(const void *a, const void *b){return ((*(ll *)a-*(ll *)b)>0?-1:1);}

int main()
{
	int t;
	scanf("%d",&t);
	For(test,t)
	{
		int n;
		scanf("%d",&n);
	}
	return 0;
}