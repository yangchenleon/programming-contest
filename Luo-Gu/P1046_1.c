#include <stdio.h>
int main()
{
    int a[10], tmp, cnt=0;
    int i;
    for(i=0; i<10; i++)
    scanf("%d", a+i);
    scanf("%d", &tmp);
    tmp+=30;
    for(i=0; i<10; i++)
        if(tmp>=a[i]) cnt++;
    printf("%d", cnt);
    return 0;
}