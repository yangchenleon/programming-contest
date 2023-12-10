# include <bits/stdc++.h>
using namespace std;

string s[25];
int cnt[25];
int n,l=0;

int mutual(string s1, string s2)
{
    int i, flag=0;
    int l1=s1.length(),l2=s2.length(),l=min(l1,l2);
    for(i=1;i<=l;i++)
    {
        if(flag==1) break;
        if(s1[l1-i]==s2[0])
        {
            int j;
            for(j=1;j<i;j++)
                if(s1[l1-i+j]!=s2[j]) break;
            if(j==i) flag=1;
        }
    }
    i--;
    if(flag==1 && i<l) return i;
    else if(flag==1 && i==l) return -1;
    else if(flag==0) return 0;
}

void dfs(string snow,int lnow)
{
    l=max(l,lnow);
    for(int i=0;i<n;i++)
    {
        int c=mutual(snow,s[i]);
        if(c>0 && cnt[i]<2)
        {
            cnt[i]++;
            dfs(s[i],lnow+s[i].length()-c);
            cnt[i]--;
        }
    }
    
    return ;
}

int main()
{
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>s[i];
    dfs(' '+s[n],s[n].length());
    cout<<l;
    /* cout<<mutual("at","atide")<<endl;
    cout<<mutual("beast","aastonish")<<endl;
    cout<<mutual("asdf","sdffds")<<endl; */
}
/*
5
at
touch
cheat
choose
tact
a
*/