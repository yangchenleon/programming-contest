# include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,na,nb;
    cin>>n>>na>>nb;
    int k1[na],k2[nb];
    for(int i=0;i<na;i++) cin>>k1[i];
    for(int i=0;i<nb;i++) cin>>k2[i];
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++) {
        int a, b;
        a=k1[i%na];
        b=k2[i%nb];
        if(a==4) {
            cnt1+=(b==0 || b==1);
            cnt2+=(b==2 || b==3);
        }
        else if(b==4) {
            cnt2+=(a==0 || a==1);
            cnt1+=(a==2 || a==3);
        }
        else {
            cnt1+=(b-a>1 || a-b==1);
            cnt2+=(a-b>1 || b-a==1);
        }
    }
    cout<<cnt1<<' '<<cnt2;
}