/*
Template by Sai Suman Chitturi
Linkedin: https://www.linkedin.com/in/sai-suman-chitturi-9727a2196/
Hackerrank: skynetasspyder
Codechef: suman_18733097
Codeforces: saisumanchitturi
Github: ChitturiSaiSuman
Hackerearth: chitturi7
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

#define and 									&&
#define or 										||
#define not 									!
#define is 										==
#define newline 								printf("\n")
#define space									printf(" ")
#define endl									printf("\n")
#define iter(x,a,b) 							for(int x=a;x<=b;x++)
#define FOR(x,N) 								for(int x=0;x<N;x++)
#define For(x,N) 								for(int x=0;x<N;x++)
#define caseprint 								printf("Case #%d: ",test+1)
#define inverse(a) 								power(a,mod-2,mod)
#define scan(a) 								scanf("%d",&a)
#define print(a) 								printf("%lld",((ll)a))
#define println(a)								printf("%lld\n",((ll)a))
#define read(arr,maxN)							FOR(x,maxN) {scan(arr[x]);}
#define write(arr,maxN)							FOR(x,maxN) {print(arr[x]);space;}
#define fill(arr,maxN,value)					FOR(x,maxN) {arr[x] = value;}
#define sort(arr,maxN)							qsort(arr,maxN,sizeof(int),ascending)
#define reverse(arr,maxN)						FOR(x,maxN/2) {arr[x]=arr[maxN-x-1];}
#define newInt(maxN)							(int*)malloc(sizeof(int)*maxN)
#define newLL(maxN)								(ll *)malloc(sizeof(ll)*maxN)

typedef unsigned long long int ull;
typedef long long int ll;
const ll mod = 1000000007; // 10**9+7

static inline void swapInt(int *a, int *b) 		{int temp=*a;*a=*b;*b=temp;}
static inline void swapChar(char *a, char *b)	{char c=*a;*a=*b;*b=c;}
static inline void swapLong(ll *a, ll *b)		{ll temp=*a;*a=*b;*b=temp;}
static inline int setBitCount(ll n)				{int ans=0;for(;n>0;n/=2,ans+=n%2);return ans;}
static inline ll gcd(ll a, ll b) 				{for(ll rem;b>0;rem=a%b,a=b,b=rem);return a;}
static inline ll lcm(ll a, ll b) 				{return (a*b)/(gcd(a,b));}
static inline ll max(ll a, ll b) 				{return (a>b?a:b);}
static inline ll min(ll a, ll b) 				{return (a<b?a:b);}
static inline ll mul(ll a, ll b) 				{return ((a%mod*b%mod)%mod);}
static inline ll add(ll a, ll b) 				{return ((a%mod+b%mod)%mod);}
static inline ll sub(ll a, ll b) 				{return ((a%mod-b%mod)+mod)%mod;}
static inline int sumOfDigits(ll n) 			{return n>0?n%10+sumOfDigits(n/10):0;}
static inline int numberOfDigits(ll n)			{return n>0?1+numberOfDigits(n/10):0;}

int ascending (const void *a, const void *b)	{return *(int*)a-*(int*)b>=0?1:-1;}
int descending(const void *a, const void *b)	{return *(int*)b-*(int*)a>=0?1:-1;}

ll power(ll x, ll y, ll p)
{
	ll result=1;
	for(;y>0;y>>=1,x=((x%p)*(x%p))%p)
	{
		if(y&1)
			result=((result%p)*(x%p))%p;
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
	int first;
	int second;
}tuple;

int compare(const void*a,const void*b)
{
	return ((*(tuple*)a).first-(*(tuple*)b).first)>=0?1:-1;
}

#define size 1000003 // 10**6+3

void preCompute()
{
	return;
}

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
		// caseprint;
		int n;
		scan(n);
		char s[size];
		scanf("%s",s);
		print(n);
		newline;
	}
	return 0;
}
