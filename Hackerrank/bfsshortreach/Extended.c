/*
* Comparator for Qsort-Integers-Ascending *************************
*/
/*
int compare(const void *v1, const void *v2)
{
	ll a=*(ll *)v1;
	ll b=*(ll *)v2;
	if(a is b)
		return 0;
	return (a>b?1:-1);
}
*/
/*
* Comparator for Qsort-Integers-Descending *************************
*/
/*
int compare(const void *v1, const void *v2)
{
	ll a=*(ll *)v1;
	ll b=*(ll *)v2;
	if(a is b)
		return 0;
	return (a>b?-1:1);
}
*/
/*
* Comparator for Qsort-Float-Ascending *******************************
*/
/*
int compare(const void *v1, const void *v2)
{
	double a=*(double *)v1;
	double b=*(double *)v2;
	if(a is b)
		return 0;
	return (a>b?1:-1);
}
*/
/*
* Comparator for Qsort-Float-Descending *******************************
*/
/*
int compare(const void *v1, const void *v2)
{
	double a=*(double *)v1;
	double b=*(double *)v2;
	if(a is b)
		return 0;
	return (a>b?-1:1);
}
*/
/*
* Binary Search on Integer Array ****************************************
*/
/*
int binary_search(int a[], int lb, int ub, int key)
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
/*
* Longest Common Subsequence of Strings (LCS) *************
*/
/*
int lcs(char s1[], char s2[], int m, int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
			if(i==0 or j==0)
				dp[i][j] = 0;
			else if(s1[i] == s2[j])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	return dp[m][n];
}
*/
/*
* GCD and LCM of two numbers *********************
*/
/*
ll gcd(ll a, ll b)
{
	while(b>0)
	{
		ll rem=a%b;
		a=b;
		b=rem;
	}
	return a;
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}
*/
/*
* Maximum Sub Sequence Sum ********************
*/
/*
ll max_Subsequence_Sum(const int a[], int n)
{
	ll this_sum,max_sum;
	this_sum=max_sum=0;
	for(int i=0;i<n;i++)
	{
		this_sum+=a[i];
		if(this_sum>max_sum)
			max_sum=this_sum;
		else if(this_sum<0)
			this_sum=0;
	}
	return max_sum;
}
*/
/*
* Sieve for Prime Generation *********************************************
*/
/*
bool prime[size]={false};
void sieve()
{
	prime[2]=true;
	for(int i=3;i<size;i+=2)
		prime[i]=true;
	for(int i=3;i*i<size;i+=2)
		if(prime[i])
			for(int j=i*i;j<size;j+=i)
				prime[j]=false;
}
*/
/*
* Sieve for Prime Generation and Count of Primes **************************
*/
/*
int prime[size]={0};
int count[size]={0};
void sieve()
{
	prime[2]=1;
	for(int i=3;i<size;i+=2)
		prime[i]=1;
	for(int i=3;i*i<size;i+=2)
		if(prime[i])
			for(int j=i*i;j<size;j+=i)
				prime[j]=0;
	for(int i=1;i<size;i++)
		count[i]=count[i-1]+prime[i];
}
*/
/*
* Sieve for Prime Generation and Sum of Primes ***************************
*/
/*
int prime[size]={0};
long sum[size]={0};
void sieve()
{
	prime[2]=1;
	for(int i=3;i<size;i+=2)
		prime[i]=1;
	for(int i=3;i*i<size;i+=2)
		if(prime[i])
			for(int j=i*i;j<size;j+=i)
				prime[j]=0;
	for(int i=1;i<size;i++)
		sum[i]=sum[i-1]+prime[i]*i;
}
*/
/*
* Factorisation in O(sqrt(n)) 
*/
/*
int factors(ll n)
{
	int ans=1;
	int c=0;
	while(n%2 is 0)
	{
		n/=2;
		c++;
	}
	ans*=c+1;
	c=0;
	while(n%3 is 0)
	{
		n/=3;
		c++;
	}
	ans*=c+1;
	for(int i=5;i<=sqrt(n);i+=6)
	{
		c=0;
		while(n%i is 0)
		{
			n/=i;
			c++;
		}
		ans*=c+1;
		c=0;
		while(n%(i+2) is 0)
		{
			n/=(i+2);
			c++;
		}
		ans*=c+1;
	}
	if(n>2)
		ans*=2;
	return ans;
}
*/
/*
* Sieve for Factorisation for Multiple Queries ***************************
*/
/*
int spf[size]={0};
void sieve()
{
	for(int i=1;i<size;i+=2)
		spf[i]=i;
	for(int i=2;i<size;i+=2)
		spf[i]=2;
	for(int i=3;i*i<size;i+=2)
		if(spf[i] is i)
			for(int j=i*i;j<size;j+=i)
				if(spf[j] is j)
					spf[j]=i;
}
int factorise(int n)
{
	int ans = 1;
	while(n>1)
	{
		int c=0;
		int f=spf[n];
		while(spf[n] is f)
		{
			n/=spf[n];
			c++;
		}
		ans*=c+1;
	}
	return ans;
}
*/
/*
* Sieve for Prime-Check in sqrt(n) ***************************************
*/
/*
bool is_prime(ll n)
{
	if(n is 0 or n is 1)
		return false;
	else if(n is 2 or n is 3)
		return true;
	else if(n%2 is 0 or n%3 is 0)
		return false;
	for(int i=5;i<=sqrt(n);i+=6)
		if(n%i is 0 or n%(i+2) is 0)
			return false;
	return true;
}
*/
/*
* Euler's Totient Function ****************************************
*/
/*
int phi[size]={0};
void computeTotient()
{
	for(int i=0;i<size;i++)
		phi[i]=i;
	for(int i=2;i<size;i++)
		if(phi[i] is i)
			for(int j=i;j<size;j+=i)
				phi[j]-=phi[j]/i;
}
*/
/*
* Nth Fibonacci Number in log(n) **********************************
*/
/*
void dot(ll a[][2],ll b[][2],ll res[][2])
{
	ll result[2][2];
	result[0][0]=add(mul(a[0][0],b[0][0]),mul(a[0][1],b[1][0]));
	result[0][1]=add(mul(a[0][0],b[0][1]),mul(a[0][1],b[1][1]));
	result[1][0]=add(mul(a[1][0],b[0][0]),mul(a[1][1],b[1][0]));
	result[1][1]=add(mul(a[1][0],b[0][1]),mul(a[1][1],b[1][1]));
	FOR(i,2)
		FOR(j,2)
			res[i][j] = result[i][j];
}
int fibonacci(ll n)
{
	ll result[2][2]={{1,0},{0,1}};
	ll base[2][2]={{1,1},{1,0}};
	if(n<2)
		return n;
	while(n>0)
	{
		if(n&1)
			dot(base,result,result);
		dot(base,base,base);
		n>>=1;
	}
	return ((int)(result[0][1]));
}
*/
/*
* Fast Modular Exponentiation *************************************
*/
/*
ll power(ll x, ll y, ll p)
{
	x=x%p;
	if(x < 2)
		return x;
	ll result=1;
	for(;y>0;y>>=1,x=mul(x,x))
		if(y&1)
			result = mul(result,x);
	return result;
}
*/
/*
* Count set_bits *****************************************************
*/
/*
* Fermat's Principle for ncr mod p ************************************
*/
/*
ll fact[size]={1};
void generate_factorials()
{
	for(int i=1;i<size;i++)
		fact[i]=(fact[i-1]*i)%mod;
}
ll ncr_mod_p(ll n, ll r)
{
	if(r is 0)
		return 1;
	return mul(mul(fact[n],inverse(fact[r])), inverse(fact[n - r]));
}
*/
/*
* Stack ADT ********************************************************
*/
/*
typedef struct stack
{
	int data;
	struct stack *next;
}stack;
stack *new_stack(int data)
{
	stack *node = (stack *)malloc(sizeof(stack));
    node->data=data;
    node->next=NULL;
	return node;
}
stack* pop(stack *node)
{
	stack * temp = node;
	if(node is NULL)
		return NULL;
	node=node->next;
	free(temp);
    return node;
}
stack* push(stack *node,int data)
{
	stack *temp = (stack *)malloc(sizeof(stack));
	temp->data=data;
	temp->next=node;
	node=temp;
    return node;
}
bool isEmpty(stack *node)
{
    return (node is NULL);
}
void print_stack(stack *node)
{
    stack *temp=node;
    while(!isEmpty(temp))
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
*/
/*
* Doubly Linked List ADT ******************************************************
*/
/*
typedef struct queue
{
	int data;
	struct queue *next;
    struct queue *prev;
}queue;
queue *new_queue(int data)
{
    queue *node = (list *)malloc(sizeof(queue));
    node->data=data;
    node->prev=NULL;
    node->next=NULL;
    return node;
}
queue *append(queue *node, int data)
{
    queue *temp = (queue*)malloc(sizeof(queue));
    temp->data=data;
    temp->prev=node;
    temp->next=NULL;
    node->next=temp;
    node=temp;
    return node;
}
queue *delete(queue *node)
{
    if(node->next is NULL)
        return NULL;
    queue *temp=node;
    node=node->next;
    free(temp);
    node->prev=NULL;
    return node;
}
queue *pop(queue *node)
{
	if(node->prev is NULL)
		return NULL;
	queue *temp=node;
	node=node->prev;
	free(temp);
	node->next=NULL;
	return node;
}
bool isEmpty(queue *node)
{
    return node is NULL;
}
void print_queue(queue *node)
{
    queue *temp = node;
    while (!isEmpty(temp))
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
	printf("\n");
}
*/
/*
* Insort: Insertion Sort Position Finder in log(n) ********
*/
/*
int insort(int a[], int n, int key)
{
	int lb=0;
	int ub=n-1;
	int mid=(lb+ub)/2;
	while(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(a[mid] is key)
			return mid;
		else if(a[mid]<key)
			lb=mid+1;
		else
			ub=mid-1;
	}
	return ub+1;
}
*/
/*
* Any and All as of in Python
*/
/*
bool any(int a[], int n, int key)
{
	for(int i=0;i<n;i++)
		if(a[i]%key is 0)
			return true;
	return false;
}
bool all(int a[], int n, int key)
{
	for(int i=0;i<n;i++)
		if(a[i]%key!=0)
			return false;
	return true;
}
*/