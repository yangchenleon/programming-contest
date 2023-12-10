# include <bits/stdc++.h>
# define MAX_N 1000;
using namespace std;

int re_num(int n)
{
    int num=0;
    if(n==0) return 0;
    while(n/10==0) n/=10;
    while(n)
    {
        num*=10;
        num+=n%10;
        n/=10;
    }
    return num;
}

int main()
{
    int n;
    cin>>n;
    if(n<=0)
    {
        cout<<'-';
        cout<<re_num(-n);
    }
    else cout<<re_num(n);
}