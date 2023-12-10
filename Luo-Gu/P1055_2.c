#include <stdio.h>
int main()
{
    char a[9], b;
    int c, sum=0;
    scanf("%c-%c%c%c-%c%c%c%c%c-%c", a,a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,&b);
    for(int i=0; i<9; i++)
        sum+=((i+1)*(a[i]-'0'));
    c= sum %11;
    if(c==10) c='X';
    else c+='0';
    if(b==c) printf("Right");
    else printf("%c-%c%c%c-%c%c%c%c%c-%c",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],c);
    return 0;
}