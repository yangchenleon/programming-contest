/* 
 * 有一个从0开始左右无线延展的格子，每个各自向左-1，向右+1；
 * 有一个骰子，有a, b, -a, -b四个整数代表格子的移动，求掷出4个整数各多少次可以到达1，无解则输出-1
 * 
 * 没看懂题解，应该是求方程，先跳过了
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