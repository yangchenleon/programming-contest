#include <stdio.h>
int main()
{
    int n, a, cnt=1,max=0;
    scanf("%d", &n);
    scanf("%d", &a);
    for(int i=1; i<n;i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if(tmp==a+1) cnt++;
        else cnt=1;
        a=tmp;
        if(cnt>max) max=cnt;
        
    }
    printf("%d\n", max);
    return 0;
}