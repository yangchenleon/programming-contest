# include <bits/stdc++.h>
using namespace std;

pair<int, int> k[5050];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second==b.second) return a.first<b.first;
    else return a.second>b.second;

}

int main()
{
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>k[i].first>>k[i].second;
    sort(k, k+n, cmp);
    for(int i=0;k[i].second>=k[m+m/2-1].second;i++)
        cnt++;
    cout<<k[m+m/2-1].second<<' '<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<k[i].first<<' '<<k[i].second<<endl;
}