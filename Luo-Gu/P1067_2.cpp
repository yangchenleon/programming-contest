# include <bits/stdc++.h>
using namespace std;

int main()
{
    /* �ӵ����£�
    ��һ��ǰ�ޡ�+����
    ��������һ�����ǲ�ͬ�ĸ���
    ע��ϵ��Ϊ1��-1��0����� */
    int n,a;
    cin>>n;
    for(int i=n;i>0;i--) {
        cin>>a;
        if(a==0) continue;
        if(a<0) {
            cout<<'-';
            if(a!=-1) cout<<abs(a);
        }
        if(a>0) {
            if(i!=n) cout<<'+';
            if(a!=1) cout<<abs(a); 
        }
        //if(abs(a)!=1) cout<<abs(a);
        if(i==1) cout<<'x';
        else cout<<"x^"<<i;
    }
    cin>>a;
    if(a==0) return 0;
    else cout<<(a>0?'+':'-')<<abs(a);

    /* ���е�����ļ��
    cin>>a;
    if(a){    //��0ϵ��
        if(i!=n&&a>0)cout<<"+";    //�����������Ƿ�Ϊ��ߴ�������Ӻ�
        if(abs(a)>1||i==0)cout<<a;    //���ϵ����ϵ����Ϊ����1��ָ��Ϊ0��
        if(a==-1&&i)cout<<"-";    //-1ϵ�����У�������������
        if(i>1)cout<<"x^"<<i;    //���μ��������ָ��
        if(i==1)cout<<"x";    //һ���� */
}