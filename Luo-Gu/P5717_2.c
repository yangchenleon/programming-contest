#include <stdio.h>
int main()
{
    int a[3], tmp;
    scanf("%d%d%d", a,a+1,a+2);
    if(a[0]>a[1]){tmp=a[0]; a[0]=a[1]; a[1]=tmp;}
    if(a[1]>a[2]){tmp=a[1]; a[1]=a[2]; a[2]=tmp;}
    if(a[0]>a[1]){tmp=a[0]; a[0]=a[1]; a[1]=tmp;}
    
    int d = a[0]*a[0];
    int b = a[1]*a[1];
    int c = a[2]*a[2];

    if(a[0]+a[1]<=a[2]) 
    {
        printf("Not triangle\n");
        return 0;
    }
    if(d+b==c) printf("Right triangle\n");
    else if(d+b>c) printf("Acute triangle\n");
    else if(d+b<c) printf("Obtuse triangle\n");
    if(a[0]==a[1] || a[2]==a[1]) printf("Isosceles triangle\n");
    if(a[1]==a[0] && a[1]==a[2]) printf("Equilateral triangle\n");
    return 0;
}