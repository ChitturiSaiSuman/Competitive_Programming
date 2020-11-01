#include<stdlib.h>
#include <stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    { long long int n,p,x=0;
       char s1[100],s3[100],s2[100],s4[100];
      scanf("%lld",&n);
      scanf("%s",s1);
      scanf("%s %lld",s2,&x);
      int b[60]={0},j=0,res=0,i;
      p=n;
      int flag=1;
      while(p)
      { b[j]=p%2;
       p=p/2;
       j++;
      }
      for(i=j-1;i>=0;i--)
      { if(b[i]==1)
         res++;
         else
         { if(res&1)
            { printf("%s\n",s1);
                flag=0;
                break;
            }
            else
            res=0;
         }
      }
      if (flag==1)
      { if (strcmp(s1,"Karthik")==0)
         printf("Suman\n");
         else
         printf("Karthik\n");
      }
      if (n%(x+1)==0)
      { if(strcmp(s2,"Karthik")==0)
         printf("Suman\n");
         else
         printf("Karthik\n");
      }
      else
      { printf("%s\n",s2);}
    }
      return 0;}