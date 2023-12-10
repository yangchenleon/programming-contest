#include <stdio.h>
int main()
{
    float n, sum = 0, step = 2;
    int cnt = 0;
    scanf("%f", &n);
    while (sum < n)
    {
        sum += step;
        cnt++;
        step *= 0.98;
    }
    printf("%d", cnt);
    return 0;
}