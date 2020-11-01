#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<limits.h>
#include<stdbool.h>
#include<time.h>
#define and &&
#define or ||
#define not !
#define is ==
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define size ((int)(1e6+1))
#define mod ((int)(1e9+7))
typedef long long int ll;
void solve()
{
    char string[size];
    scanf("%s",string);//Scan the entire number into a String
    int length = strlen(string);
    int num;
    assert(length<size);
    if(length>1)
        num=(string[length-1]-'0')+10*(string[length-2]-'0');// Taking the last two digits of the Number
    else
        num=(string[length-1]-'0');// Taking the last digit of the Number
    int remainder = num%4; // Remainder when the Number is divided by 4
    if(remainder is 0)
        printf("%s",string);
    else if(remainder is 1)
        printf("1");
    else if(remainder is 2)
    {
        string[length-1]++;
        printf("%s",string);
    }
    else
        printf("0");
    printf("\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    assert(t>0 and t<((int)(1e5+1)));
    for(int test = 0; test < t; test ++)
    {
        solve();
    }
    return 0;
}