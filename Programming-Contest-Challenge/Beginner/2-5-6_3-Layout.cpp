/* 
 * 有编号从1到N的N头牛排成一排，有些牛想保持距离，有些牛想靠近，求1到N头牛的最大距离
 * 
 * 图问题可表示为对于任意条边，都有d(v)+w>=d(u)，则d(s)-d(v)的最大值对应最短距离（记最短距离为d）
 */
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAX_N 1000
#define MAX_M 20000
using namespace std;

int N, ML, MD;
struct edge {int from, to, cost;};
edge es[MAX_M];
bool update;
int d[MAX_N];

/* void change(int &x, int y)
{
    if(x > y) {
        x = y;
        update = true;
    }
}

void bellman_ford()
{
    for(int k = 0; k <= N; k++) {
        update  = false;
        for(int i = 0; i+1 < N; i++){
            if(d[i+1] < INF) change(d[i], d[i+1]);
        }
        int M = ML + MD;
        for(int i = 0; i < M;i++) {
            edge e = es[i];
            if(d[e.from] < INF) change(d[e.to], d[e.from] + e.cost);
        }
    }
} */

void bellman_ford()
{
    for(int k = 0; k < N; k++) { // 如果循环结束还是false，存在负环
        update = false;
        for(int i = 0; i + 1 < N; i++) {
            if(d[i+1] < INF && d[i] > d[i+1]) {
                d[i] = d[i+1];
                update = true;
            }
        }
        int M = ML + MD;
        for(int i = 0; i < M; i++) {
            edge e = es[i];
            if(d[e.from] < INF && d[e.from] + e.cost < d[e.to]) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
    }
}

void solve()
{
    fill(d, d + N, 0);
    bellman_ford();
    if(update) {
        printf("-1\n");
        return;
    }

    fill(d, d + N, INF);
    d[0] = 0;
    bellman_ford();
    int res = d[N-1];
    if(res == INF) res = -2;
    printf("%d\n", res);
}

int main()
{
    scanf("%d %d %d", &N, &ML, &MD);
    for(int i = 0; i < ML + MD; i++) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        if(i < ML) es[i] = (edge){s-1, t-1, c};
        else es[i] = (edge){t-1, s-1, -c};
    }
    solve();
    return 0;
}

/* 
input1
4 2 1
1 3 10
2 4 20
2 3 3

input2
4 0 4
1 2 3
2 3 4
3 4 5
4 1 1
*/