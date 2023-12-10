# include <bits/stdc++.h>
# define MAX_N 1000;
using namespace std;

int main()
{
    /* 计算得差，带入公式计算 */
    /* 重点在于开 long long变量 */
    long long a, b, n;
    cin>>a>>b>>n;
    cout<<(a+(b-a)*(n-1)+a)*n/2;
}