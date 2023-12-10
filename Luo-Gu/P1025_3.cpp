# include <bits/stdc++.h>
using namespace std;

int count(int n, int k, int start)
{
    if(k==1) return 1;
    else {
        int cnt=0;
        for(int i=start; i<=n/k; i++)
            cnt+=count(n-i,k-1,i);
        return cnt;
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<count(n,k,1);
}