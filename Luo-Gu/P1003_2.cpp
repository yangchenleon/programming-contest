# include <bits/stdc++.h>
using namespace std;

typedef int carpet[4];
carpet cps[10010];

int main()
{
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>cps[i][0]>>cps[i][1]>>cps[i][2]>>cps[i][3];
    }
    cin>>a>>b;
    for(int i=n-1;i>=0;i--) {
        if(a>=cps[i][0] && b>=cps[i][1] && a<=cps[i][0]+cps[i][2] && b<=cps[i][1]+cps[i][3]) {
            cout<<i+1;
            return 0;
        }  
    }
    cout<<-1;
}