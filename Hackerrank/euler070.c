#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>
#define size ((int)(1e7+3))
int phi[size];
void totient()
{
    for(int i=0;i<size;i++)
        phi[i]=i;
    for (int p=2; p<size; p++) 
    { 
        // If phi[p] is not computed already, 
        // then number p is prime 
        if (phi[p] == p) 
        { 
            // Phi of a prime number p is 
            // always equal to p-1. 
            phi[p] = p-1; 
  
            // Update phi values of all 
            // multiples of p 
            for (int i = 2*p; i<size; i += p) 
            { 
               // Add contribution of p to its 
               // multiple i by multiplying with 
               // (1 - 1/p) 
               phi[i] = (phi[i]/p) * (p-1); 
            } 
        } 
    }
}
bool have_same_digits(int n1, int n2)
{
    int count1[10]={0},count2[10]={0};
    while(n1>0)
    {
        count1[n1%10]++;
        n1/=10;
    }
    while(n2>0)
    {
        count2[n2%10]++;
        n2/=10;
    }
    for(int i=0;i<10;i++)
        if(count1[i]!=count2[i])
            return false;
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    totient();
    // for(int i=2;i<100;i++)
    //     printf("%d %d\n",i,phi[i]);
    int ans=0;
    double minimum = 100000000;
    for(int i=2;i<n;i++)
    {
        if(have_same_digits(i,phi[i]))
        {
            double temp = ((double)((double)(i))/((double)(phi[i])));
            if(temp<minimum)
            {
                minimum=temp;
                ans=i;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
