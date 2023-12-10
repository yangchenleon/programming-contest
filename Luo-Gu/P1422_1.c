#include <stdio.h>
int main()
{
    int a;
    double b;
    scanf("%d", &a);
    if (a <= 150)
        b = 0.4463 * a;
    else if (a <= 400)
        b = 0.4463 * 150 + 0.4663 * (a - 150);
    else
        b = 0.4463 * 150 + 0.4663 * (400 - 150) + 0.5663 * (a - 400);
    printf("%.1f", b);
    return 0;
}