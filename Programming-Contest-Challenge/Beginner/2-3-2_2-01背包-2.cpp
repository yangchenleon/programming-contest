/* 
 * 在01背包的基础上扩大的规模，不过是重量变得很大，单个价值上限在100
 * 之前是对不同重量求最大值，这里是不同价值求重量最小值 
 */
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAX_N 100
#define MAX_V 100
using namespace std;

int n, W;
int w[MAX_N];
int v[MAX_N];
int dp[MAX_N+1][MAX_N*MAX_V+1];

void solve()
{
    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= MAX_N * MAX_V; j++) {
            if(j < v[i]) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]] + w[i]);
            }
        }
    }
    int res;
    for(int i = 0; i <= MAX_N * MAX_V; i++) {
        if(dp[n][i] <= W) {
            res = i;
        }
    }
    printf("%d\n", res);
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