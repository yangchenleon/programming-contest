/* 
 * 之前方法存在同一分支执行了两遍 
 * 在此基础上加入记忆化数组，即DP
 * 可转换为递推式，从而用二重循环实现
 * 还可以重复利用一个数组实现（从后往前修改否则前面的数据会影响到后面的），不过使用不当有风险 
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 100
using namespace std;

int n, W;
int w[MAX_N];
int v[MAX_N];
int dp[MAX_N+1][MAX_N+1]; // 记忆化数组
int dp2[MAX_N+1];

// 从第i个物品开始挑选总重小于j的部分
int rec(int i, int j)
{
    int res;
    if(i == n) {
        res = 0; // 已经没有剩余物品了
    } else if(j < w[i]) { 
        res = rec(i+1, j); // 无法挑选这个物品
    } else {
        res = max(rec(i+1, j), rec(i+1, j-w[i])+v[i]); // 挑选和不挑选两种情况都尝试一下
    }
    return res;
}

void solve()
{   
    memset(dp, -1, sizeof(dp)); // 1. 通过记忆化搜索
    printf("%d\n", rec(0, W));

    memset(dp, 0, sizeof(dp)); // 2. 通过递推式
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= W; j++) {
            if(j < w[i]) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
    
    memset(dp2, 0, sizeof(dp2)); // 3. 精简复用数组
    for(int i = 0; i < n; i++) {
        for(int j = W;j >= w[i]; j--) {
            dp2[j] = max(dp2[j], dp2[j-w[i]] + v[i]);
        }
    }
    printf("%d\n", dp2[W]);
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
4 5
2 3
1 2
3 4 
2 2
*/