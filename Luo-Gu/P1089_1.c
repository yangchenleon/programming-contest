#include <stdio.h>
int main()
{
    int cost, jin=0,mom=0;
    for(int i=0; i<12;i++)
    {
        scanf("%d", &cost);
        int add=(jin+300-cost)/100*100;
        mom+=add;
        jin+=300-cost-add;
        if(jin<0)
        {
            printf("-%d\n",i+1);
            return 0;
        }
    }
    printf("%d", mom/5+mom+jin);
    return 0;
}