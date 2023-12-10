/* 
 * ��Ŀ��������������λ��nλ�������־�д���֣���iλ��ɻ�ý�ң�ǰ�������˵����ֳ˻�/�������֣�����ȡ�������������˾�������
 * 
 * ����˼·������̰�ģ����Լ�Ҳ�³����ˣ����ǰ��������ֳ˻���С���򣨳˻�����С��Ȼ�����������Ӧ��Խ��Խ�󣩣���Ȼ���ǲ�֪��Ϊʲô
 * ���������������ģ���Ϊa�ķ�Χ10000���˻��ͺܴ�ܴ��Ǹ߾������⣬���ᴦ�����python
 */
#include <iostream>
#include <algorithm>
#define MAX_N 1005
using namespace std;

int n;
struct node {
    int a, b;
} p[MAX_N];

bool cmp(node p1, node p2) {return p1.a * p1.b <  p2.a * p2.b;}

void solve()
{
    int sum = 1, mx = -1;
    sort(p + 1, p + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        sum *= p[i-1].a;
        mx = max(mx, sum / p[i].b);
    }
    cout<<mx;
}

int main()
{
    cin>>n;
    for(int i = 0; i <= n; i++) {
        cin>>p[i].a>>p[i].b;
    }
    solve();
    return 0;
}

/* 
input
3 
1 1 
2 3 
7 4 
4 6 
*/