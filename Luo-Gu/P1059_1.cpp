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
/* ��set STL set�е�Ԫ���Ѿ��Ǵ�С�����źõ�
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
		s.insert(a[i]); //����ĳ��Ԫ��
	}
	cout<<s.size()<<endl;
	while(!s.empty())
	{
		cout<<*s.begin()<<" ";  //ע��˴����÷�,����set�����ĵ�һ��Ԫ�ص� ��ַ,end()ͬ��
		s.erase(s.begin());	 //ɾ��������ָ��it��Ԫ��
	}
	return 0;
 }
 */