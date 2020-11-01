#include <stdio.h>			
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

#define and 									&&
#define or 										||
#define not 									!
#define is 										==
#define newline 								printf("\n")
#define space									printf(" ")
#define endl									newline
#define iter(x,a,b) 							for(int x=a;x<=b;x++)
#define FOR(x,n) 								for(int x=0;x<n;x++)
#define For(x,n) 								FOR(x,n)
#define caseprint 								printf("Case #%d: ",test+1)
#define inverse(a) 								power(a,mod-2)
#define scan(a) 								scanf("%d",&a)
#define print(a) 								printf("%lld",((ll)a))
#define println(a)								printf("%lld\n",((ll)a))
#define read(arr,maxN)							FOR(x,maxN) scan(arr[x])
#define write(arr,maxN)							FOR(x,maxN) {print(arr[x]);space;}
#define fill(arr,maxN,value)					FOR(x,maxN) arr[x] = value
#define SORT123(arr,maxN)						qsort(arr,maxN,sizeof(int),ascending)
#define SORT321(arr,maxN)						qsort(arr,maxN,sizeof(int),descending)
#define newIntArray(n)							(int*)malloc(sizeof(int)*n)
#define newLLArray(n)							(ll *)malloc(sizeof(ll)*n)

typedef unsigned long long int ull;
typedef long long int ll;
const ll mod = 1000000007; // 10**9+7

static inline void swap_int(int *a, int *b) 	{int temp=*a;*a=*b;*b=temp;}
static inline void swap_char(char *a, char *b)	{char c=*a;*a=*b;*b=c;}
static inline void swap_long(ll *a, ll *b)		{ll temp=*a;*a=*b;*b=temp;}
static inline int set_bit_count(ll n)			{int ans=0;for(;n>0;n/=2,ans+=n%2);return ans;}
static inline ll gcd(ll a, ll b) 				{for(ll rem;b>0;rem=a%b,a=b,b=rem);return a;}
static inline ll lcm(ll a, ll b) 				{return (a*b)/(gcd(a,b));}
static inline ll max(ll a, ll b) 				{return (a>b?a:b);}
static inline ll min(ll a, ll b) 				{return (a<b?a:b);}
static inline ll mul(ll a, ll b) 				{return ((a%mod*b%mod)%mod);}
static inline ll add(ll a, ll b) 				{return ((a%mod+b%mod)%mod);}
static inline ll sub(ll a, ll b) 				{return ((a%mod-b%mod)+mod)%mod;}
static inline int sum_of_digits(ll n) 			{return n>0?n%10+sum_of_digits(n/10):0;}
static inline int number_of_digits(ll n)		{return n>0?1+number_of_digits(n/10):0;}

int ascending (const void *a, const void *b)	{return *(int*)a-*(int*)b>=0?1:-1;}
int descending(const void *a, const void *b)	{return *(int*)b-*(int*)a>=0?1:-1;}

ll power(ll x, ll y)
{
	ll result=1;
	for(;y>0;y>>=1,x=mul(x,x))
	{
		if(y&1)
			result=mul(result,x);
	}
	return result;
}

bool is_prime(ll n)
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
	int first;
	int second;
}tuple;

int compare(const void*a,const void*b)
{
	return ((*(tuple*)a).first-(*(tuple*)b).first)>=0?1:-1;
}

#define size 1000003 // 10**6+3

void solve()
{
	return;
}

int main()
{
	int t=0;
	if(!t) scan(t);
	For(test,t)
	{
		int n;
		scan(n);
		newline;
	}
	return 0;
}
