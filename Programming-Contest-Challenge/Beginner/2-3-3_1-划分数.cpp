/* 
 * 有n个无区别的物品，将其划分为不超过m组，求出划分方法个数（模M的结果）
 * 通过划分是否刚好是m个作为划分（注意是“不超过”） 
 */
#include <cstdio>
#define MAX_N 1000
#define MAX_M 1000
#define M 10000; // 模
using namespace std;

int n, m;
int dp[MAX_M+1][MAX_N+1]; // j的i划分个数

void solve()
{
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(j - i >= 0) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % M;
            } else {
                dp[i][j] = dp[i-1][j]; //不超过嘛，5个分成不超过6，相当于分成5
            }
        }
    }
    printf("%d\n", dp[m][n]);
}

int main()
{
    scanf("%d%d", &n, &m);
    solve();
    return 0;
}

/* 
input
4 3
*/