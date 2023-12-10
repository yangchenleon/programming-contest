/* 
 * 在部分和基础上，对不同数增加了数量
 * 有n中数字，每种m个，判断是否可以选出若干使其恰好为K
 * dp[i+1][j]表示前i种能否合成j
 */
#include <cstdio>
#include <cstring>
#define MAX_N 100
#define MAX_K 100000
using namespace std;

int n, K;
int a[MAX_N];
int m[MAX_N];
bool dp[MAX_N+1][MAX_K+1];
int dp2[MAX_K+1];

void solve()
{
    dp[0][0] = true; // 一般法，复杂度大，不过好理解
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= K; j++) {
            for(int k = 0; k <= m[i] && k * a[i] <= j; k++) {
                dp[i+1][j] |= dp[i][j-k*a[i]];
            }
        }
    }
    if(dp[n][K]) printf("Yes\n");
    else printf("No\n");

    memset(dp2, -1, sizeof(dp2)); // 布尔值转化为得到j所需第i个数的个数+数组重复利用
    dp2[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= K; j++) {
            if(dp2[j] >= 0) {
                dp2[j] = m[i];
            } else if(j < a[i] || dp2[j-a[i]] <= 0) { // 走到这里说明前i-1无法合成j，那么试试第i个;两种情况，要么加了超过，要么再加就不够了
                dp2[j] = -1;
            } else {
                dp2[j] = dp2[j-a[i]] - 1; // 表明到达此处消耗一个第i个物品
            }
        }
    }
    if(dp2[K]) printf("Yes\n");
    else printf("No\n");
}

int main()
{
    scanf("%d%d", &n, &K);
    for(int i = i; i < n; i++) {
        scanf("%d%d", &a[i], &m[i]);
    }
    solve();
    return 0;
}

/* 
input
3 17
3 3
5 2
8 2
*/
