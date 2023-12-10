#include <stdio.h>
int main()
{
    int n, k=1;
    double sum=0;
    scanf("%d", &n);
    while(sum<=n)
    {
        sum+=1.0/k++;
    }
    printf("%d", k-1);
    return 0;
}