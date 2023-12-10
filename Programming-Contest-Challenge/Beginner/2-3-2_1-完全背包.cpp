/* 
 * 在背包问题基础上令每个物品可以拿多次
 * 推导式为d[i+1][j] = max{dp[i][j-k*w[i]]+k*v[i]}
 * 包含了不包含了和包含了k个情况（只要还能装得下）
 * 增强版本：d[i+1][j]（k个但假设第k个先不选）和d[i+1][j-w[i]]（k-1个）的情况是一样的
 * 可以理解为当j扩大，是否继续装第i个
 * 同理，可复用数组实现精简
 * 因为之涉及到dp[i] 和 dp[i+1]，于是可两个数组滚动
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 100
using namespace std;

int n, W;
int w[MAX_N];
int v[MAX_N];
int dp[MAX_N+1][MAX_N+1];
int dp2[MAX_N+1];
int dp3[2][MAX_N+1];

void solve()
{
    
    memset(dp, 0, sizeof(dp)); // 1. 初版
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= W; j++) { // 注意这里j是要取到W的，i是因为i+1的存在不能取到
            for(int k = 0; k * w[i] <= j; k++) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-k*w[i]] + k*v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
   
    memset(dp, 0, sizeof(dp)); // 2. 增强版
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= W; j++) {
            if(j < w[i]) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
   
    memset(dp2, 0, sizeof(dp2)); // 3. 复用数组精简版
    for(int i = 0; i < n; i++) {
        for(int j = w[i]; j <= W; j++) {
            dp2[j] = max(dp2[j], dp2[j-w[i]] + v[i]);
        }
    }
    printf("%d\n", dp2[W]);
    
    memset(dp3, 0, sizeof(dp3)); // 4. 循环复用（和上一种差不多）
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= W; j++) {
            if(j < w[i]) {
                dp3[(i+1)&1][j] = dp3[i&1][j]; // &1判断奇偶，奇数1偶数0
            } else {
                dp3[(i+1)&1][j] = max(dp3[i&1][j], dp3[(i+1)&1][j-w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp3[n&1][W]);
}

int main()
{
    scanf("%d%d", &n, &W);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }
    solve();
    return 0;
}

/* 
input
3 7
3 4
4 5
2 3
*/