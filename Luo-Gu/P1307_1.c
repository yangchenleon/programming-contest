#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("-");
        n = -n;
    }
    while (n % 10 == 0)
        n /= 10;
    while (n)
    {
        printf("%d", n % 10);
        n /= 10;
    }
    return 0;
}