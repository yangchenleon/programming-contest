#include <stdio.h>
int main()
{
    int n, cnt = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%02d", cnt++);
        printf("\n");
    }
    cnt = 1;
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + i < n - 1; j++)
            printf("  ");
        for (int j = 0; j < i + 1; j++)
            printf("%02d", cnt++);
        printf("\n");
    }
    return 0;
}