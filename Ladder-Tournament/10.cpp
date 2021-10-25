# include <bits/stdc++.h>
using namespace std;

stack<int> s;

int k[11000][11000];
int slove(int i)
{
    if(k[i][0]==0) return 1;
    else
    {
        int mx=0;
        for(int j=1;j<=k[i][0];j++)
        {
            int tmp=slove(k[i][j])+1;
            if(tmp>mx) 
            {
                mx=tmp;
                k[i][0]=j;
            }
        }
        return mx;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k[i][0];
        for(int j=1;j<=k[i][0];j++)
        {
            cin>>k[i][j];
        }
    }
    cout<<slove(0);
}