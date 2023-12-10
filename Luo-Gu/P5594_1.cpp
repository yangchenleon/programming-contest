# include <bits/stdc++.h>
# define MAX_N 1000;
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    int cnt[k+1]={0};

    int s[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>s[i][j];  
    for(int j=0;j<m;j++)
    {
        int tmp_cnt[k+1]={0};
        for(int i=0;i<n;i++)
        {
            tmp_cnt[s[i][j]]++;
        }
        for(int i=0;i<k+1;i++)
        {
            if(tmp_cnt[i]!=0)
                cnt[i]++;
        }
    }

    for(int i=1; i<=k;i++)
    {
        cout<<cnt[i]<<' ';
    }
}