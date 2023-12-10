/* 
 * 递归嘛，自己调用自己
 * 计算阶乘的函数是典型案例
 * 还有斐波那契，单纯用递归会重复调用，可通过记忆数组优化
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 1000
using namespace std;

int n, m;
int memo[MAX_N+1];

int fact(int n)
{
    if(n == 0) return 1;
    return n * fact(n - 1);
}

/* int fib(int n) // 基础版本
{
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
} */

int fib(int n)
{
    if(n <= 1) return n;
    if(memo[n] != 0) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

void solve()
{
    fill(memo, memo + MAX_N, 0);
    printf("%d\n%d\n", fact(n), fib(m));
}

int main()
{
    scanf("%d%d", &n, &m);
    solve();
    return 0;
}

/* 
input
3 5
*/