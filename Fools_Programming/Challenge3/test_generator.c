#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<time.h>
#define size 6000100
bool prime[size];
int distance[size]={0};
struct element
{
    int position;
    int distance;
};
struct element *temp;
void sieve()
{
    int i,j;
    for(i=0;i<size;i++)
        prime[i]=true;
    prime[0]=prime[1]=false;
    for(i=2;i*i<size;i++)
        if(prime[i])
            for(j=i*i;j<size;j+=i)
                prime[j]=false;
    i=(size-1);
    int pos;
    pos=size-1;
    while(i>=0)
    {
        if(prime[i])
        {
            pos=i;
            distance[i]=0;
        }
        else
        {
            distance[i]=pos-i;
        }
        i--;
    }
}
void merge(struct element e[], int lb, int ub)
{
    int i,j,k=0;
    int mid=(lb+ub)/2;
    i=lb;
    j=mid+1;
    while(i<=mid&&j<=ub)
    {
        if(e[i].distance<=e[j].distance)
        {
            temp[k].distance=e[i].distance;
            temp[k++].position=e[i++].position;
        }
        else
        {
            temp[k].distance=e[j].distance;
            temp[k++].position=e[j++].position;
        }
    }
    while(i<=mid)
    {
        temp[k].distance=e[i].distance;
        temp[k++].position=e[i++].position;
    }
    while(j<=ub)
    {
        temp[k].distance=e[j].distance;
        temp[k++].position=e[j++].position;
    }
    k=0;
    i=lb;
    while(i<=ub)
    {
        e[i].distance=temp[k].distance;
        e[i++].position=temp[k++].position;
    }
}
void mergesort(struct element *e, int lb, int ub)
{
    int mid=(lb+ub)/2;
    if(lb<ub)
    {
        mergesort(e,lb,mid);
        mergesort(e,mid+1,ub);
        merge(e,lb,ub);
    }
}
int main()
{
    sieve();
    struct element *e;
    e=(struct element*)malloc(size*sizeof(struct element));
    temp=(struct element*)malloc(size*sizeof(struct element));
    int t,n,a,i;
    char input[]="input00.txt";
    char output[]="output00.txt";
    FILE *in,*out;
    srand(time(0));
    int test=20;
    while(test--)
    {
        in=fopen(input,"w");
        out=fopen(output,"w");
        t=(rand()%10)+1;
        fprintf(in,"%d\n",t);
        while(t--)
        {
            n=(rand()%100)+1;
            fprintf(in,"%d\n",n);
            for(i=0;i<n-1;i++)
            {
                a=(rand()%999)+2;
                fprintf(in,"%d ",a);
                e[i].distance=distance[a];
                e[i].position=(i+1);
            }
            a=(rand()%999)+2;
            fprintf(in,"%d\n",a);
            e[i].distance=distance[a];
            e[i].position=(i+1);
            mergesort(e,0,n-1);
            for(i=0;i<n-1;i++)
            {
                fprintf(out,"%d ",e[i].position);
            }
            fprintf(out,"%d\n",e[i].position);
        }
        fclose(in);
        fclose(out);
        if(input[6]=='9')
        {
            input[6]='0';
            input[5]++;
            output[7]='0';
            output[6]++;
        }
        else
        {
            input[6]++;
            output[7]++;
        }
    }
}
