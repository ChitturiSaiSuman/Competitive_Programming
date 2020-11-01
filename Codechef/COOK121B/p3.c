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
#define newline printf("\n");
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define size ((int)(1e6+2))
#define mod ((int)(1e9+7))
typedef unsigned long long int ull;
typedef long long int ll;
// int gcd(int a, int b)
// {
// 	while(b>0)
// 	{
// 		int rem=a%b;
// 		a=b;
// 		b=rem;
// 	}
// 	return a;
// }
void reverse(char s[],int length)
{
	for(int i=0;i<length/2;i++)
		s[i]=(s[length-i-1]+s[i])-(s[length-1-i]=s[i]);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int test = 0; test<t;test++)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		char s[1004];
		scanf("%s",s);
		int count_0=0,count_1=0;
		for(int i=0;i<n;i++)
			count_1+=s[i]-'0';
		count_0=n-count_1;
		int number_of_segments=n/k;
		if(count_0%number_of_segments!=0 or count_1%number_of_segments!=0)
			printf("IMPOSSIBLE\n");
		else
		{
			int zero=count_0/number_of_segments;
			int one=count_1/number_of_segments;
			// printf("This: %d %d\n",zero,one);
			char ans[1003];
			int i=0;
			for(i=0;i<zero;i++)
				ans[i]='0';
			for(;i<zero+one;i++)
				ans[i]='1';
			// printf("THIS: %s\n",ans);
			ans[i]='\0';
			// printf("THis: %d",n/k);
			for(i=0;i<n/k;i++)
			{
				printf("%s",ans);
				reverse(ans,one+zero);
			}
			printf("\n");
		}
		
	}
	return 0;
}
