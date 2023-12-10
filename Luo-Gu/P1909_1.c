#include <stdio.h>
int main()
{
    int n, cost;
    int min = 9999999;
    scanf("%d", &n);
    for(int i=0; i<3; i++)
    {
         int a,b;
        scanf("%d %d", &a, &b);
        cost = b*(n/a+(n%a?1:0));
        if(cost<min) min=cost;
    }
    printf("%d", min);
    return 0;
}