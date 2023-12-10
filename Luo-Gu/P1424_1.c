#include <stdio.h>
int main()
{
    int a, b;
    int week, day = 0;
    scanf("%d %d", &a, &b);
    week = b / 7;
    day = week * 5;
    int res = b%7;
    int jud = a + res-1;
    if (a <= 6)
    {
        if (jud <= 5)
            day += res;
        else if (jud == 6)
            day += res - 1;
        else
            day += res - 2;
    }
    if (a == 7)
        day += res - (res==0?0:1); //处理 7 0

    printf("%d", day * 250);
    return 0;
}