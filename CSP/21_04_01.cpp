#include <bits/stdc++.h>
using namespace std;

int n,m,L;

int main()
{
    cin>>n>>m>>L;
    int h[L];
    memset(h,0,sizeof(h));
    for(int i=0;i<n*m;i++)
    {
        int tmp;
        cin>>tmp;
        h[tmp]++;
    }
    for(int i=0;i<L;i++)
    {
        cout<<h[i]<<' ';
    }
    return 0;
}
