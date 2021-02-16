/*
Author: Chitturi Sai Suman
Created: 2021-01-31 18:20:08
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
const ll mod = ((ll)(1e9+7)); // 10**9+7
const ll hell = ((ll)(1e9+9)); // 10**9+9
const ll inf = ((ll)(1e18)); // 10**18

static inline void swapInt(int *a, int *b) 		{int temp=*a;*a=*b;*b=temp;}
static inline void swapChar(char *a, char *b)	{char c=*a;*a=*b;*b=c;}
static inline void swapLong(ll *a, ll *b)		{ll temp=*a;*a=*b;*b=temp;}
static inline int setBitCount(ll n)				{int ans=0;for(;n>0;n/=2,ans+=n%2);return ans;}
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

ll power(ll x, ll y, ll p)
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

typedef struct Pair
{
	int x, y;
}Pair;

// int compare(const void *a,const void *b)
// {
// 	tuple *t1 = (tuple *)a;
// 	tuple *t2 = (tuple *)b;
// 	int v1 = t1->value;
// 	int v2 = t2->value;
// 	return v1>v2?1:-1;
// }

#define size 1000003 // 10**6+3

void preCompute()
{
	return;
}

void solve()
{
	int n,q;
	scan(n);
	scan(q);
	// assert(q != 0);
	int x, y;
	scan(y);scan(x);
	Pair *pair = (Pair*)malloc(sizeof(Pair)*q);
	FOR(i,q) {
		scanf("%d %d",&pair[i].y,&pair[i].x);
		if(pair[i].y == y and pair[i].x == x)
			assert(false);
	}
	int distance[8];
	distance[0] = n-y;
	distance[1] = min(n-x,n-y);
	distance[2] = n-x;
	distance[3] = min(n-x,y-1);
	distance[4] = y-1;
	distance[5] = min(x-1,y-1);
	distance[6] = x-1;
	distance[7] = min(x-1, n-y);
	// FOR(i,8)
	// 	debug(distance[i]);
	FOR(i,q) {
		if(pair[i].x < x and pair[i].y < y and (pair[i].x - pair[i].y) == (x-y)) {
			distance[5] = min(distance[5], x - (pair[i].x + 1));
		}
		if(pair[i].x > x and pair[i].y > y and (pair[i].x - pair[i].y) == (x-y)) {
			distance[1] = min(distance[1], pair[i].x - (x + 1));
		}
		if(pair[i].x == x and pair[i].y > y) {
			distance[0] = min(distance[0], pair[i].y - (y + 1));
		}
		if(pair[i].x == x and pair[i].y < y) {
			distance[4] = min(distance[4], y - (pair[i].y + 1));
		}
		if(pair[i].y == y and pair[i].x < x) {
			distance[6] = min(distance[6], x - (pair[i].x + 1));
		}
		if(pair[i].y == y and pair[i].x > x) {
			distance[2] = min(distance[6], pair[i].x - (x + 1));
		}
		if(pair[i].x < x and pair[i].y > y and (pair[i].x + pair[i].y) == (x + y)) {
			distance[7] = min(distance[7], min(pair[i].y - (y + 1), x - (pair[i].x + 1)));
		}
		if(pair[i].x > x and pair[i].y < y and (pair[i].x + pair[i].y) == (x + y)) {
			distance[3] = min(distance[3], min(y - (pair[i].y + 1), pair[i].x - (x + 1)));
		}
	}
	// FOR(i,8)
	// 	debug(distance[i]);
	ll ans = 0;
	FOR(i,8)
		ans = ans + ((ll)(distance[i]));
	println(ans);
}

int main()
{
	int t=1;
	if(!t) scan(t);
	preCompute();
	For(test,t)
	{
		// caseprint;
		solve();
	}
	return 0;
}