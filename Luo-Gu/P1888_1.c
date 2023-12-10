#include <stdio.h>
int Gcd(int M, int N)
{
    int Rem;
    while (N > 0)
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}
int main()
{
    int a, b, c;
    int max, min;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
    if (c > max)
        max = c;
    if (c < min)
        min = c;
    int divn = Gcd(max, min);
    printf("%d/%d", min / divn, max / divn);
    return 0;
}