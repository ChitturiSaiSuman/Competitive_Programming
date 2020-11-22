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
#define print(a) 				printf("%lld",((ll)a))
#define println(a)				printf("%lld\n",((ll)a))
#define read(arr,nax)			FOR(x,nax) {scan(arr[x]);}
#define write(arr,nax)			FOR(x,nax) {print(arr[x]);space;}
#define fill(arr,nax,value)		FOR(x,nax) {arr[x] = value;}
#define sort123(arr,nax)		qsort(arr,nax,sizeof(int),ascending)
#define sort321(arr,nax)		qsort(arr,nax,sizeof(int),descending)
#define reverse(arr,nax)		FOR(x,nax/2) {arr[x]=arr[nax-x-1];}
#define newInt(nax)				(int*)malloc(sizeof(int)*nax)
#define newLong(nax)			(ll *)malloc(sizeof(ll)*nax)
#define newString(nax)			(char *)malloc(sizeof(char)*nax)

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

int ascending (const void *a, const void *b)	{return *(int*)a-*(int*)b>=0?1:-1;}
int descending(const void *a, const void *b)	{return *(int*)b-*(int*)a>=0?1:-1;}

typedef struct tuple
{
	int first;
	int second;
}tuple;

int compare(const void*a,const void*b)
{
	return ((*(tuple*)a).first-(*(tuple*)b).first)>=0?1:-1;
	// return ((*(tuple*)a).second-(*(tuple*)b).second)>=0?1:-1;
}

int binarySearch(int [], int, int, int);
ll power(ll, ll, ll);
bool isPrime(ll);
void matmul(ll **, ll **, ll **, int, int, int, ll);
ll nthFibonacci(ll);
void powr(ll **, int, ll);

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
		
	}
	return 0;
}

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

int binarySearch(int a[], int lb, int ub, int key)
{
    while(lb<=ub)
    {
        int mid=(lb+ub)/2;
        if(a[mid] is key)
            return mid;
        else if(a[mid]<key)
            lb=mid+1;
        else
            ub=mid-1;
    }
    return -1;
}

void matmul(ll **a, ll **b, ll **result, int m, int n, int p, ll modulo)
{
	ll **res = (ll **)malloc(sizeof(ll*)*m);
	FOR(i,m)
		res[i] = newLong(p);
	FOR(i,m)
	{
		FOR(j,p)
		{
			res[i][j] = 0;
			FOR(k,n)
				res[i][j] = add(res[i][j],mul(a[i][k],b[k][j],modulo),modulo);
		}
	}
	FOR(i,m)
		FOR(j,p)
			result[i][j] = res[i][j];
	FOR(i,m)
		free(res[i]);
	free(res);
}

void powr(ll **a, int n, ll x)
{
	ll **result = (ll **)malloc(sizeof(ll*)*n);
	FOR(i,n)
		result[i] = newLong(n);
	FOR(i,n)
		result[i][i] = 1;
	for(;x>0;x>>=1,matmul(a,a,a,n,n,n,mod))
		if(x&1)
			matmul(a,result,result,n,n,n,mod);
	FOR(i,n)
		FOR(j,n)
			a[i][j] = result[i][j];
	FOR(i,n)
		free(result[i]);
	free(result);
}

ll nthFibonacci(ll n)
{
	ll **fib = (ll **)malloc(sizeof(ll*)*2);
	FOR(i,2)
		fib[i] = newLong(2);
	fib[0][0] = fib[0][1] = fib[1][0] = 1; fib[1][1] = 0;
	powr(fib,2,n);
	ll ans = fib[0][1];
	FOR(i,2)
		free(fib[i]);
	free(fib);
	return ans;
}