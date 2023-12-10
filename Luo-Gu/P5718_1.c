#include <stdio.h>
int main()
{
    int n, num;
    int min=1001;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if(tmp<min) min=tmp;
    }
    printf("%d",min);
    return 0;
}