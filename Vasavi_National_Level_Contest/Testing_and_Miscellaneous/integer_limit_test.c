#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
#include<math.h>
#include<stdbool.h>
#include<assert.h>
typedef unsigned long long int ull;
typedef long long int ll;
int main()
{
    ll fact[100]={1};
    for(int i=1;i<100;i++)
    {
        fact[i]=fact[i-1]*i;
        if(fact[i]<fact[i-1])
            printf("Error: %d\n",i);
        printf("%d %lld\n",i,fact[i]);
        
    }
    return 0;
}