#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[3], tmp;
    char c;
    cin>>a[0]>>a[1]>>a[2];
    //getchar();
    if(a[0]>a[1]){tmp=a[0]; a[0]=a[1]; a[1]=tmp;}
    if(a[1]>a[2]){tmp=a[1]; a[1]=a[2]; a[2]=tmp;}
    if(a[0]>a[1]){tmp=a[0]; a[0]=a[1]; a[1]=tmp;}
    for(int i=0; i<3;i++)
    {
        cin>>c;
        printf("%d%s", a[c-65],i==2?"":" ");
    }
    return 0;  
}