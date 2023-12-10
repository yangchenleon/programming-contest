/* 
 * 并查集:用于管理分组，执行查询是否同一组、合并操作，但无法拆分
 * 避免退化（节点少但树高），采取小高接大高、路径压缩（直接连根、经过的连带连根）
 * 操作的均摊复杂度是a(n)，比logn还要快
 * 
 * 问题概述：N个动物，编号1-N，都属于ABC其中一种，已知A吃B、B吃C、C吃A，
 * 按序给出K条记录，记录仅两种，x和y属于同一种、x吃y
 * 前后可能有矛盾，之处错误个数
 * 
 * 解题：设置3N，代表N个动物分别属于ABC的事件。
 * 同一组内的事件要么同时发生，要么同时不发生
 * 对于type1的判断：如果x-A y-C 发生过，说明C吃A发生过，
 * 此时必然x-B y-A、x-C y-B在同一组，所以这些都不同额外判定
 * 对于type2的判断：如果x-A y-A在同一组，那么x-B y-B也是一组
 * 总之就是如果x-A情况下和y是A或C在同一组，那么x-B情况下也会满足和y-C或A一组
 * 果然在AC过程中，并查集的大小还是设置得太小了
 */
#include <cstdio>
#include "UFSet.h"
#define MAX_N 50000
#define MAX_K 100000
using namespace std;

int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];

void solve()
{
    init(N * 3); // 初始化并查集，每N个分别代表x-A、x-B、x-C，意思就是i+0就是A类，+N就是B类，+2N就是C类
    
    int ans = 0;
    for(int i = 0; i < K; i++) {
        int t = T[i];
        int x = X[i] - 1, y = Y[i] - 1; // 并查集是从0开始的，需转换
        if(x < 0 || N <= x || y < 0 || N <= y) {
            ans++; // 这种属于越界错误，并直接跳过接下来的判定
            continue;
        }
        if(t == 1) {
            if(same(x, y + N) || same(x, y + 2 * N)) { 
                ans++;
            } else {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }
        }
        if(t == 2) {
            if(same(x, y) || same(x, y + 2 * N)) {
                ans++;
            } else {
                unite(x, y + N);
                unite(x + N, y + 2 * N);
                unite(x + 2 * N, y);
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < K; i++) {
        scanf("%d %d %d", &T[i], &X[i], &Y[i]);
    }
    solve();
    return 0;
}

/* 
input
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
*/