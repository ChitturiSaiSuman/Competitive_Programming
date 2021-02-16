/*
Author: Chitturi Sai Suman
Created: 2021-02-05 18:39:47
*/
/*
Linkedin: https://www.linkedin.com/in/sai-suman-chitturi-9727a2196/
Hackerrank: https://www.hackerrank.com/skynetasspyder?hr_r=1
Codechef: https://www.codechef.com/users/suman_18733097
Codeforces: http://codeforces.com/profile/saisumanchitturi
Github: https://github.com/ChitturiSaiSuman
Hackerearth: https://www.hackerearth.com/@chitturi7
SPOJ: Sai Suman Chitturi @out_of_bound
*/

//	  _____   _    _   __    __     ____     __    _
//	 / ____| | |  | | |  \  /  |   /    \   |  \  | |
//	 | |___  | |  | | |   \/   |  /   _  \  | . \ | |
//	 \____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
//	 ____| | | \__/ | | |    | | |   __   | | | \ ` |
//	 |_____/ \______/ |_|    |_| |__|  |__| |_|  \__|
//
						
#include <stdio.h>			
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

#define and 					&&
#define or 						||
#define not 					!
#define is 						==
#define newline 				printf("\n")
#define space					printf(" ")
#define endl					printf("\n")
#define iter(x,a,b) 			for(int x=a;x<=b;x++)
#define FOR(x,N) 				for(int x=0;x<N;x++)
#define For(x,N) 				for(int x=0;x<N;x++)
#define caseprint 				printf("Case #%d: ",test+1)
#define inverse(a,p) 			power(a,p-2,p)
#define scan(a) 				scanf("%d",&a)
#define scanll(a)				scanf("%lld",&a)
#define print(a) 				printf("%lld",((ll)a))
#define println(a)				printf("%lld\n",((ll)a))
#define getName(var)			#var
#define debug(var)				fprintf(stderr,"%s = %lld\n",getName(var),((ll)var));
#define readInt(arr,nax)		FOR(IT,nax) {scan(arr[IT]);}
#define readLL(arr,nax)			FOR(IT,nax) {scanll(arr[IT]);}
#define write(arr,nax)			FOR(IT,nax) {print(arr[IT]);space;}
#define fill(arr,nax,value)		FOR(IT,nax) {arr[IT] = value;}
#define sort123(arr,nax)		qsort(arr,nax,sizeof(int),ascending)
#define sort321(arr,nax)		qsort(arr,nax,sizeof(int),descending)
#define reverse(arr,nax)		FOR(x,nax/2) {arr[x]=arr[nax-x-1];}
#define newInt(nax)				(int*)malloc(sizeof(int)*nax)
#define newLong(nax)			(ll *)malloc(sizeof(ll)*nax)
#define newString(nax)			(char *)malloc(sizeof(char)*nax)
#define copy(from,to,nax)       FOR(IT,nax) {to[IT] = from[IT];}

typedef unsigned long long int ull;
typedef long long int ll;
// const ll mod = ((ll)(1e9+7)); // 10**9+7
const ll mod = 998244353LL;
const ll hell = ((ll)(1e9+9)); // 10**9+9
const ll inf = ((ll)(1e18)); // 10**18

static inline void swapInt(int *a, int *b) 		{int temp=*a;*a=*b;*b=temp;}
static inline void swapChar(char *a, char *b)	{char c=*a;*a=*b;*b=c;}
static inline void swapLong(ll *a, ll *b)		{ll temp=*a;*a=*b;*b=temp;}
static inline int setBitCount(ll n)				{int ans=0;for(;n>0;ans+=(n&1),n>>=1);return ans;}
static inline ll gcd(ll a, ll b) 				{for(ll rem;b>0;rem=a%b,a=b,b=rem);return a;}
static inline ll lcm(ll a, ll b) 				{return (a*b)/(gcd(a,b));}
static inline ll max(ll a, ll b) 				{return (a>b?a:b);}
static inline ll min(ll a, ll b) 				{return (a<b?a:b);}
static inline ll mul(ll a, ll b, ll p) 			{return ((a%p*b%p)%p);}
static inline ll add(ll a, ll b, ll p) 			{return ((a%p+b%p)%p);}
static inline ll sub(ll a, ll b, ll p) 			{return ((a%p-b%p)+p)%p;}
static inline int sumOfDigits(ll n) 			{return n>0?n%10+sumOfDigits(n/10):0;}
static inline int numberOfDigits(ll n)			{return n>0?1+numberOfDigits(n/10):0;}
static inline void LLFraction(ll *a, ll *b) 	{ll g = gcd(*a,*b); (*a)/=g; (*b)/=g;}
static inline void IntFraction(int *a, int *b)	{int g = gcd(*a,*b); (*a)/=g; (*b)/=g;}

int ascending (const void *a, const void *b)	{return *(int*)a>=*(int*)b?1:-1;}
int descending(const void *a, const void *b)	{return *(int*)b>=*(int*)a?1:-1;}

static inline ll power(ll x, ll y, ll p)
{
	ll result=1;
	for(;y>0;y>>=1,x=mul(x,x,p))
	{
		if(y&1)
			result = mul(result,x,p);
	}
	return result;
}

bool isPrime(ll n)
{
	if(n==0 or n==1)
		return false;
	else if(n==2 or n==3)
		return true;
	else if(n%2==0 or n%3==0)
		return false;
	for(int i=5;i<=sqrt(n);i+=6)
		if(n%i==0 or n%(i+2)==0)
			return false;
	return true;
}

typedef struct tuple
{
	int value;
}tuple;

int compare(const void *a,const void *b)
{
	tuple *t1 = (tuple *)a;
	tuple *t2 = (tuple *)b;
	int v1 = t1->value;
	int v2 = t2->value;
	return v1>v2?1:-1;
}

#define size 200003 // 2 * 10**5 + 3

ll fact[size]={1};
ll inv[size] = {0};

void generate_factorials()
{
	for(int i=1;i<size;i++)
		fact[i]=(fact[i-1]*i)%mod;
	for(int i=0;i<size;i++)
		inv[i] = inverse(fact[i], mod);
}

static inline ll ncr_mod_p(ll n, ll r)
{
	if(n is 0)
		return 1;
	else if(n < r)
		return 0;
	else if(r is 0)
		return 1;
	else if(r < 0)
		return 0;
	else if(n == r)
		return 1;
	return mul(mul(fact[n],inv[r], mod), inv[n - r], mod);
}


void preCompute()
{
	generate_factorials();
}

ll* build(int n) {
	int bits[32] = {0};
	fill(bits, 32, 0);
	FOR(i,n) {
		ll a;
		scanll(a);
		FOR(j,32) {
			bits[j] += (a&(1LL));
			a /= 2;
		}
	}
	ll *ans = newLong(size);
	ans[0] = 0;
	FOR(i,n) {
		int m = i + 1;
		ll count = 0;
		FOR(j,32) {
			int count_1 = bits[j];
			int count_0 = n - count_1;
			ll ways = 0;
			for(int k=1;k <= count_1;k+=2) {
				ll term1 = ncr_mod_p(count_1, k);
				ll term2 = ncr_mod_p(count_0, m - k);
				ll current = mul(term1, term2, mod);
				current = mul(current, (1LL << j), mod);
				ways = add(ways, current, mod);
			}
			count = add(count, ways, mod);
		}
		// debug(count);
		ans[m] = add(ans[m-1], count, mod);
	}
	return ans;
}


void solve()
{
	return;	
}

int main()
{
	int t=1;
	if(!t) scan(t);
	preCompute();
	For(test,t)
	{
		// caseprint;
		int n;
		scan(n);
		ll *ans = build(n);
		// free(a);
		int q;
		scan(q);
		FOR(Q,q) {
			int m;
			scan(m);
			println(ans[m]);
		}
	}
	return 0;
}