/* 
 * 问题描述：有编号1-N的罪犯，要释放一名罪犯，其左右侧直到空房间的所有罪犯都要给一枚硬币，
 * 现要释放某些房间的罪犯，求最少需要多少硬币
 * 
 * 解题思路：permutation枚举所有可能，设置状态数组，记录是是否为空, 左侧右侧计数到直到空格, 将当前格的值为空
 * 但显然太复杂了，用dp[i][j]表示A[i],A[j]之间（不包含两头）的连续部分里所有罪犯都释放的最小金币总数，
 * 然后是相当于二叉树分解的逆过程，自底向上分析，一开始是区间内含0个，递增到含Q个需释放囚犯，代码中用w间隔表示
 * 从区间中选出代价最小的即可，大致理清楚了，不过还是很懵逼啊
 */
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAX_N 10000
#define MAX_Q 100
using namespace std;

int P, Q;
int A[MAX_Q+2]; // 释放罪犯的编号，下标从1开始

bool used[MAX_Q];
int perm[MAX_Q];
int ans = INF;
void permutation(int pos, int n)
{
    if(pos == n) {
        bool empty[P+1];
        fill(empty, empty + P + 1, false);
        int res = 0;
        empty[P+1] = empty[0] = true;
        for(int i = 0; i < n; i++) {
            int j = perm[i];
            while(!empty[++j]) res++;
            j = perm[i];
            while(!empty[--j]) res++;
            empty[perm[i]] = true;
        }
        ans = min(ans, res);
    }
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            used[i] = true;
            perm[pos] = A[i+1];
            permutation(pos + 1, n);
            used[i] = false;
        }
    }
    return;
}

int dp[MAX_Q+1][MAX_Q+2];
void solve()
{
    A[0] = 0; A[Q+1] = P + 1; // 方便处理，左端当成0号犯，右端Q+1号犯，这样dp[0][Q+1]就是答案
    for(int q = 0; q < Q; q++) dp[q][q+1] = 0;
    for(int w = 2; w <= Q + 1; w++) { // 区间长度，即包含几段，Q个点，最多切成Q+1段
        for(int i = 0; i + w <= Q + 1; i++) {
            int j = i + w, t = INF;
            for(int k = i + 1; k < j; k++) {
                t = min(t, dp[i][k] + dp[k][j]);
            }
            dp[i][j] = t + A[j] - A[i] - 2; // 释放罪犯需贿赂该区间的人，然后去掉两头
        } 
    }
    printf("%d\n", dp[0][Q+1]);
}

int main()
{
    scanf("%d%d", &P, &Q);
    for(int i = 0; i < Q; i++) {
        scanf("%d", &A[i+1]);
    }
    permutation(0, Q);
    printf("%d\n", ans);
    return 0;
}

/*
input1
8 1
3

input2
20 3
3 6 14
*/