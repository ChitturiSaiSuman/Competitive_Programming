#include<stdio.h>
int main()
{
    int t;
    int a[]={0,0,2, 4, 6, 12, 12, 24, 24, 36, 48, 60, 60, 120, 120, 120, 120, 180, 180, 240, 240, 360, 360, 360, 360, 720, 720, 720, 720, 720, 720, 840, 840, 1260, 1260, 1260, 1260, 1680, 1680, 1680, 1680, 2520, 2520, 2520, 2520, 2520, 2520, 2520, 2520, 5040, 5040, 5040, 5040, 5040, 5040, 5040, 5040, 5040, 5040, 5040, 5040, 7560, 7560, 7560, 7560, 10080, 10080, 10080, 10080, 10080, 10080, 10080, 10080, 15120, 15120, 15120, 15120, 15120, 15120, 15120, 15120, 20160, 20160, 20160, 20160, 25200, 25200, 25200, 25200, 25200, 25200, 27720, 27720, 27720, 27720, 27720, 27720, 45360, 45360, 45360, 45360, 50400, 50400, 50400, 50400, 50400, 50400, 50400, 50400, 55440, 55440, 55440, 55440, 55440, 55440, 55440, 55440, 55440, 55440, 55440, 55440, 83160, 83160, 83160, 83160, 83160, 83160, 83160, 83160, 110880, 110880, 110880, 110880, 110880, 110880, 110880, 110880, 110880, 110880, 110880, 110880, 110880, 110880, 110880, 110880, 166320, 166320, 166320, 166320, 166320, 166320, 166320, 166320, 166320, 166320, 166320, 166320, 166320, 166320, 166320, 166320, 221760, 221760, 221760, 221760, 221760, 221760, 221760, 221760, 277200, 277200, 277200, 277200, 277200, 277200, 277200, 277200, 277200, 277200, 277200, 277200, 332640, 332640, 332640, 332640, 332640, 332640, 332640, 332640, 332640, 332640, 332640, 332640, 498960, 498960, 498960, 498960, 498960, 498960, 498960, 498960};
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}