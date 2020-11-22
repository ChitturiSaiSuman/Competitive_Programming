#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>
#define and &&
bool will_jerry_win(int ts,int js)
{
    while(true)
    {
        if(ts%2==js%2 && js%2==1)
            return false;
        else if(ts%2==0 and js%2==1)
            return false;
        else if(ts%2==1 and js%2==0)
            return true;
        else
        {
            ts/=2;
            js/=2;
        }
    }
    return false;
}
int main()
{
    for(int ts=1;ts<=100;ts++)
    {
        int ans=0;
        for(int js=1;js<=ts;js++)
        {
            if(will_jerry_win(ts,js))
                ans++;
        }
        printf("%d = %d\n",ts,ans);
    }
    return 0;
}