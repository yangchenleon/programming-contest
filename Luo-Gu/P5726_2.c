#include <stdio.h>
int main()
{
    int n, tmp, max = -1, min = 11, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        max = max > tmp ? max : tmp;
        min = min < tmp ? min : tmp;
        sum += tmp;
    }
    sum -= max + min;
    printf("%.2f", (float)(sum) / (n - 2));
    return 0;
}