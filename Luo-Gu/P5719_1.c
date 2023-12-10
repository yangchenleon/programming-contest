#include <stdio.h>
int main()
{
    int n, k;
    double sum1=0, sum2=0;
    int cnt1=0, cnt2=0;

    scanf("%d%d", &n, &k);
    for(int i=1;i<=n;i++)
    {
        if(i%k) {sum1+=i;cnt1++;}
        else {sum2+=i;cnt2++;}
    }
    printf("%.1f %.1f", sum2/cnt2, sum1/cnt1);
    return 0;
}