# include <bits/stdc++.h>
using namespace std;

long long b,p,k,ans=1;

long long solve(long long y)
{
    if(y==0) return 1;
    else
    {
        long long tmp=solve(y/2);
        if(y%2)
            return tmp*tmp*b%k;
        else    
            return tmp*tmp%k;
    }
}

int main()
{
    
    cin>>b>>p>>k;
    cout<<b<<"^"<<p<<" mod "<<k<<"="<<solve(p)%k<<endl; //输出有点裹人～～ 
}