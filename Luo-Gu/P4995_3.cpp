# include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,cnt=0;
    long long sum=0;
    cin>>n;i=0;j=n;
    int h[n+1];
    h[0]=0;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    sort(h+1,h+n+1);
    while(i<j)
    {
        cnt=++cnt%2;
        sum+=(h[j]-h[i])*(h[j]-h[i]);
        j+=cnt-1;
        i+=cnt;
    }
    cout<<sum;
}