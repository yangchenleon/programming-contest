# include <bits/stdc++.h>
using namespace std;

int main()
{
    int a=0, b=1, m;
    cin>>m;
    int i=0;
    while(true)
    {
        int c;
        if(i!=0 && a%m==0 && b%m==1) {cout<<i;break;}
        c=(a+b)%m; //��û���Ϊʲô�������������
        a=b;
        b=c;
        i++;
    }
}