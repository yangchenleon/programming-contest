# include <bits/stdc++.h>
# define MAX_N 1000;
using namespace std;

int main()
{
    /* ����ò���빫ʽ���� */
    /* �ص����ڿ� long long���� */
    long long a, b, n;
    cin>>a>>b>>n;
    cout<<(a+(b-a)*(n-1)+a)*n/2;
}