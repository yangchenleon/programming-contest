# include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long n,l,t;//l原始字符串长度，t拓展到n时字符串长度，一定是l的2幂次倍数
    cin>>s>>n;
    l=t=s.length();//或strlen()
    while(t<n) t<<=1;//位运算*2
    while(t!=l)
    {
        t>>=1;
        if(n<=t) continue;//在前半段则不用处理
        if(n==t+1) n=t;//特判后半段的第一个情况
        else n-=t+1;
    }
    cout<<s[n-1];
}