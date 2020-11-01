#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>
#define or ||
#define and &&
#define not !
typedef long long int ll;
int pair[]={0,1,2,3,4,5,6,7,8,9};
void raise_error()
{
    printf("%d\n",1/0);
}
void update(int a, int b)
{
    int i;
    for(i=0;i<10;i++)
        if(pair[i]==a)
            break;
    int ind1=i;
    for(i=0;i<10;i++)
        if(pair[i]==b)
            break;
    int ind2=i;
    int value1=pair[ind1];
    int value2=pair[ind2];
    pair[ind1]=(pair[ind1]+pair[ind2])-(pair[ind2]=pair[ind1]);
    if(pair[ind2]!=value1 or pair[ind1]!=value2)
        raise_error();
}
ll reverse(ll n)
{
    ll s=0;
    while (n>0)
    {
        s=s*10+n%10;
        n/=10;
    }
    return s;
}
ll decode(ll n)
{
    ll s=0;
    while(n>0)
    {
        int digit=n%10;
        int i;
        for(i=0;i<10;i++)
            if(pair[i]==digit)
                break;
        s=s*10+i;
        n/=10;
    }
    return reverse(s);
}
ll solve(ll a, ll b, char operator)
{
    a=decode(a);
    b=decode(b);
    ll ans;
    switch(operator)
    {
        case '+': ans=a+b;
                    break;
        case '-': ans=a-b;
                    break;
        case '*': ans=a*b;
                    break;
        case '/': ans=a/b;
                    break;
        default: raise_error();
                    break;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    if(t<1 or t>1000)
        raise_error();
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a<0 or a>9 or b<0 or b>9)
            raise_error();
        update(a,b);
    }
    ll A,B;
    char operator,space;
    scanf("%lld %lld %c %c",A,B,space,operator);
    if(space!=' ')
        raise_error();
    ll result=solve(A,B,operator);
    printf("%lld",result);
    return 0;
}