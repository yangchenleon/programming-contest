# include <bits/stdc++.h>
using namespace std;

long w[1010],sum[1010],wmax=0;
int n,c;

void dfs(int rnow, long wnow)
{
    if(wnow>c) return ;
    if(wnow+sum[rnow]<=c)
    {
        wmax=max(wmax,wnow+sum[rnow]);
        return ;
    }
    wmax=max(wnow,wmax);
    for(int i=rnow;i>=1;i--)
        dfs(i-1,wnow+w[i]);
}

int main()
{
    
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        sum[i]=w[i]+sum[i-1];
    }
    dfs(n,0);
    cout<<wmax;
}
/* 
input:
3 15
1
10
20
output:
11
 */