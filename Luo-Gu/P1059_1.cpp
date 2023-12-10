# include <bits/stdc++.h>
using namespace std;

int k[110];

int main()
{
    int n, cnt=1, tmp;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>k[i];
    }
    sort(k,k+n);
    for(int i=1;i<n;i++) {
        if(k[i-1]==k[i]) continue;
        else cnt++;
    }
    cout<<cnt<<endl;
    cout<<k[0]<<' ';
    for(int i=1;i<n;i++) {
        if(k[i-1]==k[i]) continue;
        else cout<<k[i]<<' ';
    }
}
/* 用set STL set中的元素已经是从小到大排好的
#include<bits/stdc++.h>
using namespace std;
set<int>s;
int a[105];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s.insert(a[i]); //插入某个元素
	}
	cout<<s.size()<<endl;
	while(!s.empty())
	{
		cout<<*s.begin()<<" ";  //注意此处的用法,返回set容器的第一个元素的 地址,end()同理
		s.erase(s.begin());	 //删除迭代器指针it处元素
	}
	return 0;
 }
 */