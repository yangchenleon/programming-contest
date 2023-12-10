#include <stdio.h>
int main()
{
    int n,x, cnt=0;
    scanf("%d %d", &n, &x);
    for(int i=1;i<=n;i++)
    {
        int tmp=i;
        while(tmp!=0)
        {
            cnt += tmp%10==x;
            tmp/=10;
        }
    }
    printf("%d",cnt);
    return 0;
}