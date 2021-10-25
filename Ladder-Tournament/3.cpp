# include <bits/stdc++.h>
using namespace std;

char a[10];
int l(char* a)
{
    int p=0;
    while(a[p]!='\0') p++;
    return p;
}
int main()
{
    cin>>a;
    if(l(a)==4)
    {
        int p=(a[0]-'0')*10+(a[1]-'0');
        if(p<22) printf("20%c%c-%c%c",a[0],a[1],a[2],a[3]);
        else printf("19%c%c-%c%c",a[0],a[1],a[2],a[3]);
    }
    else
        printf("%c%c%c%c-%c%c",a[0],a[1],a[2],a[3],a[4],a[5]);
    return 0;
}