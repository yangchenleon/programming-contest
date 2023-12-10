# include <bits/stdc++.h>
using namespace std;

bool t_lie[15];
bool t_dj1[30];
bool t_dj2[30];
int ans[15];
int n,cnt=0;

void print()
{
    cnt++;
    if(cnt<=3)
    {
        for(int i=0;i<n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
        
}

void dfs(int i)
{
    if(i>=n)
    {
        print();
        return ;
    }
    else 
    {
        for(int j=0;j<n;j++)
        {
            if(!t_dj1[j-i+n]&&!t_lie[j]&&!t_dj2[i+j])
            {
                ans[i]=j+1;
                t_dj1[j-i+n]=1;t_lie[j]=1;t_dj2[i+j]=1;
                dfs(i+1);
                t_dj1[j-i+n]=0;t_lie[j]=0;t_dj2[i+j]=0;
            }
        }
    }
}

int main()
{
    cin>>n;
    dfs(0);
    cout<<cnt;
    return 0;
}
/*
input 6
output 
2 4 6 1 3 5
3 6 2 5 1 4
4 1 5 2 6 3
4
*/