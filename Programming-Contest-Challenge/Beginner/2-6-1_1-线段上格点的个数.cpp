/* 
 * ��֪������p1��p2�������㹹���߶��ϵĸ�����
 * 
 * ��dx��dyͬʱ�ܹ����������𣬻������ģ��������Լ����շת�����
 * ���ڸ����⣬������ͬһ����Ҫ����
 * 
 * ����һ����ֵ����⣬y1��һ������������֮�⣬y0, yn, j0, j1, jnҲ���ڽ�����
 */
#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> p1, p2;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve()
{
    int dx = abs(p1.first - p2.first), dy = abs(p1.second - p2.second);
    int ans;
    if(!dx && !dy) ans = 0;
    else ans = gcd(max(dx, dy), min(dx, dy));
    printf("%d\n", ans);
}

int main()
{
    scanf("%d%d%d%d", &p1.first, &p1.second, &p2.first, &p2.second);
    solve();
    return 0;
}

/* 
input
1 11
5 3
*/
