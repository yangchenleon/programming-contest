#include <stdio.h>
int main()
{
    int m, n;
    int min = 1001, max = -1;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &n);
        if (n > max)
            max = n;
        if (n < min)
            min = n;
    }
    printf("%d", max - min);
    return 0;
}