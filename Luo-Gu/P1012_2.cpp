# include <bits/stdc++.h>
# define MAX_N 1000;
using namespace std;

bool cmp(string a,string b) {
	return a+b>b+a;
}
int main()
{
    int n;
    cin>>n;
    string k[n];
    string s = "";
    for(int i=0;i<n;i++)
        cin>>k[i];
    sort(k,k+n,cmp);
    for(int i=0;i<n;i++)
        s+=k[i];
    cout<<s<<endl;
}