#include<bits/stdc++.h>
using namespace std;

const int N = 100015;

unordered_map<string,int> d;
unordered_map<string,vector<string>> g;

vector<string> get(string str)
{
	vector<string> res;
	string word;
	for(auto &c:str)
	{
		if(c=='.')
		{
			res.push_back(word);
			if(!d.count(word)) d[word]=0;
			word="";
		}
		else word+=c;
	}
	res.push_back(word);
	if(!d.count(word)) d[word]=0;
	return res;
}

vector<string> topsort()
{
	priority_queue<string,vector<string>,greater<string>> Q;
	for(auto &[k,v]:d) 
		if(!v)
			Q.push(k);
	
	vector<string> res;
	while(!Q.empty())
	{
		string t=Q.top();Q.pop();
		res.push_back(t);
		for(auto &p:g[t])
			if(--d[p]==0)
				Q.push(p);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int n;cin>>n;
	string str;cin>>str;
	vector<string> last=get(str);
	
	for(int i=0;i<n-1;i++)
	{
		cin>>str;
		vector<string> cur=get(str);
		if(last.size()==cur.size())
		{
			for(int j=0;j<(int)cur.size();j++)
				if(last[j]!=cur[j])
				{
					g[last[j]].push_back(cur[j]);
					d[cur[j]]++;
					break;
				}
		}
		last=cur;
	}
	
	vector<string> res=topsort();
	cout<<res[0];
	for(int i=1;i<(int)res.size();i++)
		cout<<"."<<res[i];
	return 0;
} 
