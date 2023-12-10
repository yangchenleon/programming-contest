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
int main()
{
    int n;
    scanf("%d", &n);
    int k = (int)(sqrt(n));
    if (n % 2 == 0)
        printf("%d", n / 2);
    else
        for (int i = 3; i <= k; i += 2)
        {
            if (prime(i) && n % i == 0 && prime(prime(n / i)))
                printf("%d", n / i);
        }
    return 0;
}