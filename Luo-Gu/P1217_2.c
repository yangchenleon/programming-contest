#include <stdio.h>
#include <math.h>
int prime(int n)
{
    float m = sqrt(n);
    for (int i = 2; i <= (int)(m); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int palindrome(int n)
{
    int a[10], i = 0;
    if ((1000 <= n && n <= 9999) || (100000 <= n && n <= 999999)||n>10000000)
        return 0;
    while (n != 0)
    {
        a[i++] = n % 10;
        n /= 10;
    }
    i--;
    for (int j = 0; j <= i; j++, i--)
    {
        if (a[j] != a[i])
            return 0;
    }
    return 1;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        if (i % 2 == 0)
            continue;
        else if (palindrome(i) && prime(i))
            printf("%d\n", i);
    }
    return 0;
}