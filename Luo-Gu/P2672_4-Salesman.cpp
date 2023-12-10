/* 
 * ��Ŀ����������N��ס���ľ���ʹ��ۣ�һ���ۼ�һƣ�ͣ�����Ҳ�ۼƴ���ƣ�ͣ�������һ������X�û������ƣ��ֵ
 * 
 * ����˼·��̰�ģ�����ʱ����������·�̣�����ѡƣ��ֵ���ģ���Ȼ��ѡ·������Զ�������۵Ĵ��۵ġ�
 * �����о���max(sum[i] + q[i], sum[i-1] + h[i])��ǰi������ƣ��+·�̣���ǰi-1������ƣ��+��i������ƣ�����
 * 
 * ���ⷽ��������ˣ����ǻ��ǲ�֪��֤�����̣��Լ�Ϊʲô��ô��ģ�
 * �������������ȶ��С��߶�����������������ȥ�о��ˣ������ղ���
 * ���о���֪����������ȻҲд�˺��ˣ�MD��Ϊ�ܶ�ǰ׺����������1��ʼ��
 * ���˰���һֱ��Ϊ����������⣬�����sort��ԭ�򣬷�Χ���ǰ��û�ĺ���
 */
#include <iostream>
#include <algorithm>
#define MAX_N 100005
using namespace std;

int N;
struct node{
    int d, a;
} p[MAX_N];
int sum[MAX_N], q[MAX_N], h[MAX_N];

bool cmp(node p1, node p2) {return p1.a > p2.a;}

void solve()
{
    int res;
    sort(p + 1, p + N + 1, cmp);
    for(int i = 1; i <= N; i++) {
        int j = N + 1 - i;
        sum[i] = sum[i-1] + p[i].a; // ƣ��ֵ��ǰ׺��
        q[i] = max(q[i-1], 2 * p[i].d); // ����ǰi�����������·�̣�����������
        h[j] = max(h[j+1], 2 * p[j].d + p[j].a); // ��ʾʣ��j...N�й�������һ�ң���·�̱ض���ѡ�������
    }
    for(int i = 1; i <= N; i++) {
        res = max(sum[i] + q[i], sum[i-1] + h[i]);
        cout<<res<<endl;
    }
}

int main()
{
    cin>>N;
    for(int i = 1; i <= N; i++) cin>>p[i].d;
    for(int i = 1; i <= N; i++) cin>>p[i].a;
    solve();
    return 0;
}


/*
input
5
1 2 2 4 5
5 4 3 4 1

output
12
17
21
24
27
*/