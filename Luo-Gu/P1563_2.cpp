# include <bits/stdc++.h>
using namespace std;

int main()
{
    /* 
    模拟题
    按步骤来就好，采用异或判断前进方向
     */
    int n,m;
    cin>>n>>m;
    int side[n];
    char name[n][11]; //使用string会爆仓
    for(int i=0;i<n;i++) {
        cin>>side[i]>>name[i]; 
    }
    int pos=0;
    for(int i=0;i<m;i++)
    {
        int a,s;
        cin>>a>>s;
        pos+=(a^side[pos]?1:-1)*s;
        pos=(n+pos%n)%n;
    }
    cout<<name[(n+pos%n)%n];
}