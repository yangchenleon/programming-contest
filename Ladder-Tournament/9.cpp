# include <bits/stdc++.h>
using namespace std;


int pos[101];
stack<char> sta;

int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    char a[n][m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int t;
    cin>>t;
    while(t!=-1)
    {
        if(t==0) 
        {
            if(sta.empty()) continue;
            else
            {
                cout<<sta.top();
                //cout<<"liushui\t"<<sta.top()<<endl;
                sta.pop();
            }
        }
        else
        {
            if(pos[t-1]==m) continue;
            if(sta.size()==s)
            {
                cout<<sta.top();
                //cout<<"liushui\t"<<sta.top()<<endl;
                sta.pop();
            }
            sta.push(a[t-1][pos[t-1]]);
            pos[t-1]++;
        }
        cin>>t;
    }
    return 0;
}