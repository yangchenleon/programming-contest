# include <iostream>
# include <algorithm>
# define MAX_N 100
using namespace std;

int main()
{
    int l, m;
    cin>>l>>m;
    l=l+1;
    pair<int, int> s[MAX_N];
    for(int i=0; i<m; i++)
    {
        cin>>s[i].first>>s[i].second;
        //cout<<s[i].first<<s[i].second<<endl;
    }
    sort(s,s+m);
    //cout<<s[0].first<<s[0].second<<endl;
    int start = s[0].first;
    int end = s[0].second;
    for(int i=1; i<m; i++) {
        if(s[i].first<=end && s[i].second>=end)
        {
            end=s[i].second;
        }
        if(s[i].first>end)
        {
            l=l-(end-start+1);
            start = s[i].first;
            end = s[i].second;
        }
        //cout<<start<<end<<endl;
    }
    l=l-(end-start+1);
    cout<<l;
}