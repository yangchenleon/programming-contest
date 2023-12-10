/* 
 * �ݹ���Լ������Լ�
 * ����׳˵ĺ����ǵ��Ͱ���
 * ����쳲������������õݹ���ظ����ã���ͨ�����������Ż�
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

/* int fib(int n) // �����汾
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