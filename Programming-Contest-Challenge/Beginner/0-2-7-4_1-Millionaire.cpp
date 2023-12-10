/* 
 * 问题描述：一开始有X元，就这进行M轮赌博，均有P概率将堵住翻倍，求获得1000000元的概率
 * 
 * 题解思路：难点在于连续性，赌注不一定为整，不可穷竭搜索，可化连续为离散（不知道为什么可以）
 * 于是就可以穷竭搜索了，然后改成动态规划，能求解large
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_M 15
using namespace std;
typedef long long ll;

int M, X;
double P;
double dp[2][(1<<MAX_M)+1]; // 数组复用

void solve()
{
    int n = 1 << M;
    double *prv = dp[0], *nxt = dp[2];
    memset(prv, 0, sizeof(double) * (n + 1));
    prv[n] = 1.0;

    for(int r = 0; r < M; r++) {
        for(int i = 0; i <= n; i++) {
            int jub = min(i, n - i);
            double t = 0.0;
            for(int j = 0; j <= jub; j++) {
                t = max(t, P * prv[i+j] + (1 - P) * prv[i-j]);
            }
            nxt[i] = t;
        }
        swap(prv, nxt);
    }
    int i = (ll)X * n / 1000000;
    printf("%.6f\n", prv[i]);
}

int main()
{
    scanf("%d%lf%d", &M, &P, &X); // 这里一定要用lf
    solve();
    return 0;
}

/*
input1
1 0.5 500000

input2
3 0.75 600000
*/