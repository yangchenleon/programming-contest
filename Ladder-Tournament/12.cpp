# include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,m;
    int now=1;
    cin>>n>>m;
    int a[n][n];
    int save[110];
    memset(save,1,sizeof(save));
    memset(a,1,sizeof(a));
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            cin>>a[i][j];
        }
    }
    
    for(int k=0;k<m;k++)
    {
        int i,j;
        cin>>i>>j;
        if(i==0)
        {
            save[now-1]=a[now-1][j-1];
        }
        if(i==1)
        {
            save[j-1]=save[now-1];
            cout<<"\t\t"<<save[now-1]+1<<endl;
        }
        if(i==2)
        {
            now=j-1;
        }
    }
}