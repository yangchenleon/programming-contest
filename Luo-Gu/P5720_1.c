#include <stdio.h>
int main()
{
    long int n;
    int cnt=0;
    scanf("%ld", &n);
    for(;n!=1;cnt++,n/=2);
    printf("%d",cnt+1);
    return 0;
}