# include <bits/stdc++.h>
using namespace std;
int x[25];

bool isprime(long n) {
    long i;
    for(i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

int count(int k, long sum, int start, int end)
{
    if(k==0 && isprime(sum)) return 1;
    else {
        int cnt=0;
        for(int i=start;i<=end;i++) //选中剩余的任意元素
            cnt+=count(k-1, sum+x[i], i+1, end);
        return cnt;
    }
}

int main()
{
    /* 递归解决 */
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>x[i];
    }
    cout<<count(k,0,0,n-1);
}