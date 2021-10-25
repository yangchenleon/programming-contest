# include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int mn=10000000;
    int mx=-1;
    cin>>n;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp==mn) cnt1++;
        if(tmp==mx) cnt2++;
        if(tmp<mn) {mn=tmp;cnt1=1;}
        if(tmp>mx) {mx=tmp;cnt2=1;}
        
    }
    printf("%d %d\n%d %d",mn,cnt1,mx,cnt2);
}