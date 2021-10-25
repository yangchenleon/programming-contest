# include <bits/stdc++.h>
using namespace std;

int mode[24];

int main()
{
    for(int i=0;i<24;i++)
        cin>>mode[i];
    int t;
    cin>>t;
    while(t>=0&&t<24)
    {
        printf("%d %s\n",mode[t],mode[t]>50?"YES":"NO");
        cin>>t;
    }
    return 0;
        
}