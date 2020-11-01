#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define and &&
#define or ||
int main()
{
    int t;
    srand(time(0));
    char name[][10]={"Suman","Karthik"};
    int test=8;
    int p;
    char in[]="input00.txt";
    char out[]="output00.txt";
    FILE *input,*output;
    int x1,x2,y1,y2;
    while(test--)
    {
        input=fopen(in,"w");
        output=fopen(out,"w");
        t=(rand()%100000)+1;
        fprintf(input,"%d\n",t);
        while(t--)
        {
            x1=(rand()%3)+1;
            x2=(rand()%3)+1;
            y1=(rand()%3)+1;
            y2=(rand()%3)+1;
            p=rand()%2;
            fprintf(input,"%s\n",name[p]);
            while(x1==x2 && y1==y2)
            {
                x1=(rand()%3)+1;
                x2=(rand()%3)+1;
                y1=(rand()%3)+1;
                y2=(rand()%3)+1;
            }
            fprintf(input,"%d %d %d %d\n",x1,y1,x2,y2);
            if((x1==1 and y1==1) or (x1==1 and y1==3) or (x1==3 and y1==1) or (x1==3 and y1==3))
                if(x2==2 and y2==2)
                    fprintf(output,"DRAW\n");
                else
                    fprintf(output,"%s\n",name[p]);
            else
                fprintf(output,"DRAW\n");
        }
        fclose(input);
        fclose(output);
        if(in[6]=='9')
        {
            in[6]='0';
            in[5]++;
            out[7]='0';
            out[6]++;
        }
        else
        {
            in[6]++;
            out[7]++;
        }
    }
}
