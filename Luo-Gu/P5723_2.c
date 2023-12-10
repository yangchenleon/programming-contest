#include <stdio.h>
int jud(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int n, sum=0, cnt=0;
    scanf("%d", &n);
    for(int i=2;sum+i<=n;i++)
    {
        if(jud(i)) 
        {
            sum+=i;
            cnt++;
            printf("%d\n",i);
        }
    };
    printf("%d", cnt);
    return 0;
}