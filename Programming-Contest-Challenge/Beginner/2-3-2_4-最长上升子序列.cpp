/* 
 * 求一个数字序列中最长的上升子序列，只要求i<j 且 a[i]<a[j]，不要求连续
 * 
 * 一般方法：针对末尾元素时最大长度
 * 
 * 另一种思路：针对相同长度最小的末尾元素
 * 
 * 进一步改进，易得最终dp数组一定是递增的，且上述步骤实际上就是找到仅次于a[j]的数然后更新其后一位
 * 遂采用二分，复杂度降到nlogn
 */
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAX_N 1000
using namespace std;

int n;
int a[MAX_N];
int dp[MAX_N]; // 以a[i]结尾的最长子序列长度

void solve()
{
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) { // 找刚好比a[i]小的数
            if(a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    printf("%d\n", res);

    res = 0;
    fill(dp, dp + n, INF);
    for(int i = 0; i < n; i++) { // 遍历每个元素
        for(int j = 0; j < i; j++) { // i+1即为长度
            if(a[i] > dp[j-1] || j == 0) {
                dp[j] = min(a[i], dp[j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(dp[i] < INF) {
            res = i + 1;
        }
    }
    printf("%d\n", res);

    fill(dp, dp + n, INF);
    for(int i = 0; i < n; i++) {
        *lower_bound(dp, dp + n, a[i]) = a[i]; // 利用二分搜索找出满足a中>=k的最小a[i]的地址（大于等于k的下届）
    }
    printf("%d\n", lower_bound(dp, dp + n, INF) - dp);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < 9; i++) {
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}

/* 
input
5
4 2 3 1 5
*/
