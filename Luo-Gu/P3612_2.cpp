# include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long n,l,t;//lԭʼ�ַ������ȣ�t��չ��nʱ�ַ������ȣ�һ����l��2�ݴα���
    cin>>s>>n;
    l=t=s.length();//��strlen()
    while(t<n) t<<=1;//λ����*2
    while(t!=l)
    {
        t>>=1;
        if(n<=t) continue;//��ǰ������ô���
        if(n==t+1) n=t;//���к��εĵ�һ�����
        else n-=t+1;
    }
    cout<<s[n-1];
}