# include <bits/stdc++.h>
using namespace std;

const int N=1e4+5;
string s[N],t[N];

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0); //�������
    
    long long m=0, n=0;
    long long cnt=0;
    string tmp;
    while(getline(cin,tmp), tmp!="EOF") {
        for(char i:tmp) //�����ַ������൱��for(int i=0;i<s.length();i++){s[i]....}
        {
            /* if(!s[n].empty() && i=='<') s[n].pop_back();
            else s[n].push_back(i); */
            if(i=='<'){if(!s[n].empty())s[n].pop_back();}
		    else s[n].push_back(i);//��������<��Զ������Ϊ�ַ�����
        }
        n++;
    }
    while(getline(cin,tmp), tmp!="EOF") {
        if(m>n) break; //�����в�����
        for(char i:tmp) //�����ַ������൱��for(int i=0;i<s.length();i++){s[i]....}
        {
            /* if(!t[m].empty() && i=='<') t[m].pop_back();
            else t[m].push_back(i); */
            if(i=='<'){if(!t[m].empty())t[m].pop_back();}
		    else t[m].push_back(i);
        }
        for(int i=0;i<min(s[m].size(),t[m].size());i++) {
            cnt+=s[m][i]==t[m][i];
        }
        m++;
    }
    cin>>m;
	cout<<(long long)(cnt*60.0/m+0.5);//���
}