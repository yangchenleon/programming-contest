/* 
 * 问题描述：给n个整数，是否能恰好凑成k
 * 
 * 解题思路：由于是学完动态规划回头来做的，可以用其实现，不过这个k太大了，用动态对话不太行
 * 这题用深度优先搜索就很好，不过好像没法还原路径
 * 我错了，反而动态规划不好还原路径
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 25
#define MAX_K 1000
using namespace std;

int n, k;
int a[MAX_N];
bool dp[MAX_N+1][MAX_K+1];
bool check[MAX_N];
int prv[MAX_N];

bool dfs(int i, int sum)
{
    if(i == n) return sum == k; // 已经遍历完所有节点，查看是否存在一个相等
    if(dfs(i + 1, sum)) return true; // 不加a[i]
    if(dfs(i + 1, sum + a[i])) {chcek[i] = true;return true;}
    return false;
}

void solve()
{
    fill(prv, prv + n, -1);
    dp[0][0] = true; // 动态规划
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j - a[i] >= 0) {
                dp[i+1][j] = dp[i][j-a[i]] | dp[i][j];
                if(dp[i][j-a[i]]) prv[j] = j-a[i]; // 记录的是增加前的上一个和
            } else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    if(dp[n][k]) printf("Yes\n");
    else printf("No\n");
    for(int t = k; t != 0; t = prv[t]) {
        printf("%d+", t-prv[t]);
    }
    printf("=%d\n", k);

    fill(check, check + n, false);
    bool ans = dfs(0, 0);
    if(ans) printf("Yes\n");
    else printf("No\n");
    for(int i = 0; i < n; i++) {
        if(check[i]) printf("%d+", a[i]);
    }
    printf("=%d\n", k);
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}
/* 
input1
4 11
1 2 4 7 

input2
4 15
1 2 4 7
*/