/* 
 * 在上题基础上，每种物品不止一个，要求从中选出m个，求多少组合（求模） 
 */
#include <cstdio>
#define MAX_N 1000
#define MAX_M 1000
#define M 10000 // 模
using namespace std;

int n, m;
int a[MAX_N];
int dp[MAX_N+1][MAX_M+1];

void solve()
{
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j - 1 - a[i] >= 0) {
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]] + M) % M; // 括号内加M是为了保证不为负数
            } else {
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) % M;
            }
        }
    }
    printf("%d\n", dp[n][m]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}

/* 
input
3 3
1 2 3
*/