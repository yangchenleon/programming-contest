# include <bits/stdc++.h>
# define MAX_N 1000;
using namespace std;

int main()
{
    int n, cnt=1;
    cin>>n;
    while(n>cnt)
    {
        n-=cnt;
        cnt+=1;
    }
    if(cnt%2)
        cout<<cnt-(n-1)<<'/'<<n;
    else
        cout<<n<<'/'<<cnt-(n-1);
}