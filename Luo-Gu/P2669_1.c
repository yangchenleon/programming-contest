#include <stdio.h>
int main()
{
    int n = 1, day;
    int coin = 0;
    scanf("%d", &day);
    while (n < day)
    {
        coin += n * n;
        day -= n++;
    }
    coin += day * n;
    printf("%d", coin);
    return 0;
}