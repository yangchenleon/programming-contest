#include<iostream>
#include<cstdio>
#include<cstring>

#define M 1001

using namespace std;

int visit[M][M];
int t[M][M];
int cost[M][M]; 
bool flag=false;
int n,m,maxn,mid;

void change(int x)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if (cost[i][j]<=x) t[i][j]=0;
            else t[i][j]=1;
}

void dfs(int x,int y)
{
    if(x==n-1)
    {
        flag=true;
        return;
    }
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    for(int k=0;k<4;k++)
    {
        int tx=x+d[k][0];
        int ty=y+d[k][1];
        if((tx>=0)&&(ty>=0)&&(tx<n)&&(ty<m))
        {
            if((!visit[tx][ty])&&(!t[tx][ty]))
            {
                visit[tx][ty]=1;
                dfs(tx,ty);
                if(flag==true)break;
            }
            
        }
    }
    //return;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
       {
            scanf("%d",&cost[i][j]);
            maxn=max(maxn,cost[i][j]);
       }
    int l=0;
    int r=maxn;
    while(l+1<r)
    {   
        flag=false;
        mid=(l+r)/2;
        change(mid);
        memset(visit,0,sizeof visit);
        dfs(0,0);
        if(flag) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
    return 0;
}