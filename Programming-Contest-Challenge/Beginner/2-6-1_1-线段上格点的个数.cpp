/* 
 * 已知两个点p1、p2，求两点构成线段上的格点个数
 * 
 * 求dx和dy同时能够整除的数吗，还是最大的，就是最大公约数，辗转相除法
 * 对于该问题，两点在同一点需要特判
 * 
 * 发现一个奇怪的问题，y1是一个函数，除此之外，y0, yn, j0, j1, jn也是内建函数
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
