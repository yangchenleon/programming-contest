#include <stdio.h>
#include<math.h>
long fab(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fab(n-2) + fab(n - 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    /*method 1*/
    if (n == 1 || n == 2)
        printf("%.2f", 1.0);
    else
    {
        double a = 1, b = 1, c;
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        printf("%.2f", c);
    }
    /*method 2, time limit!!
    printf("%ld.00", fab(n));
    */
    /* method 3, ok!!
    double c=sqrt(5);
    double a=(1+c)/2;
    double b = (1-c)/2;
    double sum1=1.0;
    double sum2=1.0;
    for(int i=0;i<n;i++)
    {
        sum1*=a;
        sum2*=b;
    }
    printf("%0.2f", (sum1-sum2)/c);
    */
    return 0;
}