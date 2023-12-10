# include <bits/stdc++.h>
using namespace std;

int cnt_two(int n) {
    int cnt=0;
    while(n)
    {
        if(n%10==2) cnt++;
        n/=10;
    }
    return cnt;
}

int main()
{
    /* 
    简单的模拟
    判断一个2的个数
     */
    int L,R;
    int cnt=0;
    cin>>L>>R;
    for(int i=L;i<=R;i++) {
        cnt+=cnt_two(i);
    }
    cout<<cnt;
}