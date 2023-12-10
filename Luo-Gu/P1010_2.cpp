# include <bits/stdc++.h>
using namespace std;
  
string solve(int n)
{
    string ans="";
    while(n)
    {
        int mi=1;
        int cnt=0;
        while(mi<=n)
        {
            mi*=2;
            cnt++;
        }
        cnt--;
        n-=mi/2;
        if(cnt!=1 && cnt!=0) 
            ans+="2("+solve(cnt)+")";
        else if(cnt==1)
        {   
            ans+="2";
        }
        else ans+="2(0)";
        if(n!=0) ans+="+";
        
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}