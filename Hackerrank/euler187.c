#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<limits.h>
#define size ((int)(1e8+3))
bool prime[size]={0};
int list[size];
int pos=0;
void sieve()
{
    for(int i=3;i*i<size;i+=2)
        prime[i]=true;
    for(int i=3;i*i<size;i+=2)
        if(prime[i])
            for(int j=i*i;j<size;j+=i)
                prime[j]=false;
    prime[2]=true;
    
}
