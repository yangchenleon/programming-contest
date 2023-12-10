#include <bits/stdc++.h>
using namespace std;

int n,L,r,t;
int h[700][700];
long long qz[700][700];

bool isblack(int x, int y)
{
    long double sum=0;
    int cnt=0;

    int up,down, left,right;
    if(x-r<1) left=1; else left=x-r;
    if(x+r>n) right=n; else right=x+r;
    if(y-r<1) up=1; else up=y-r;
    if(y+r>n) down=n; else down=y+r;

    for(int j=up;j<=down;j++)
    {
        sum+=qz[right][j]-qz[left-1][j];
        cnt+=right-left+1;
    }
    if(sum/cnt<=t) return true;
    else return false;

}

int main()
{
    int cnt=0;
    cin>>n>>L>>r>>t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>h[i][j];
            qz[i][j]=qz[i-1][j]+h[i][j];
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cnt+=isblack(i,j);
    cout<<cnt;
    return 0;
}
