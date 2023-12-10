# include <bits/stdc++.h>
# define N 1000010
using namespace std;

int n,m;   //n天，m订单
int s[N],t[N];  //每个订单的开始和终止
long long r[N],d[N];    //可用和租用教室
long long A[N]; //教室差分

bool check(int x)
{
    memset(A,0,sizeof(A));
    for(int i=1;i<=x;i++)
    {
        A[s[i]]+=d[i];
        A[t[i]+1]-=d[i];
    }
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=A[i];
        if(sum>r[i]) return false;
    }
    return true; 
}

int main()
{
    cin>>n>>m;
    int le=1, ri=m, ans=m;
    for(int i=1;i<=n;i++)
        cin>>r[i];
    for(int i=1;i<=m;i++)
        cin>>d[i]>>s[i]>>t[i];
    while(le<=ri)
    {
        int mi=(le+ri)/2;
        if(check(mi)) le=mi+1;
        else {ans=mi;ri=mi-1;}
    }
    if(ans==m) cout<<0;
    else cout<<-1<<endl<<ans;
}
/* 
4 3 
2 5 4 3 
2 1 3 
3 2 4 
4 2 4 
*/