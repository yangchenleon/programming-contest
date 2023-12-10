/* 
 * ��һ����0��ʼ����������չ�ĸ��ӣ�ÿ����������-1������+1��
 * ��һ�����ӣ���a, b, -a, -b�ĸ�����������ӵ��ƶ���������4�����������ٴο��Ե���1���޽������-1
 * 
 * û������⣬Ӧ�����󷽳̣���������
 */
#include <cstdio>
using namespace std;

int a, b;

int extgcd(int a, int b, int &x, int &y)
{
    int d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

void solve()
{
    int x, y;
    int ans = extgcd(a, b, x, y);
    printf("%d\n", ans);
    printf("%d %d\n", x, y);
}

int main()
{
    scanf("%d%d", &a, &b);
    solve();
    return 0;
}