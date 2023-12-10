# include <bits/stdc++.h>
# define MAX_N 1000;
using namespace std;

bool binary_search(int x, int* k, int l, int r) {    
    while(r-l>=0){
        int i = (l+r)/2;
        if(k[i]==x) return true;
        else if (k[i]<x) l=i+1;
        else r=i-1;
    }
    return false;
}

int main()
{
    int n, cnt=0;
    cin>>n;
    int k[n];
    for(int i=0; i<n; i++)
        cin>>k[i];
    sort(k,k+n);
    for(int i=2; i<n; i++) {
        for(int j=0; j<=i/2; j++) {
            if(binary_search(k[i]-k[j], k, j+1, i-1))
            {
                cnt++;
                break;
            }              
        }
    }       
    cout<<cnt;
}