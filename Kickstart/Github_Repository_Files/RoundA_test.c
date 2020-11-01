#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>
#define or ||
#define and &&
#define size 2000000
#define mod
int compare(const void *a , const void *b)
{
    return (*(int *)a)-(*(int *)b);
}
typedef unsigned long long int ull;
typedef long long int ll;
int main()
{
    int a[size];
    int i;
    for(i=0;i<size;i++)
        a[i]=size-i-1;
    qsort(a,size,sizeof(int),compare);
    printf("Done");
    return 0;
}
