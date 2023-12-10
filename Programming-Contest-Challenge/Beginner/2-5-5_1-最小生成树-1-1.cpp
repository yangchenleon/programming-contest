/* 
 * Prim�㷨��
 * ��dijstra�㷨���Ƶģ����ǰѵ�ǰ���·���Ķ���ѡ�룬Ȼ����������Ӱ���������������·��
 * ��ͬ���ڣ�������ǵ���ѡ����������һ������Ķ��㣬�޸ļ���õ�������㵽���ţ���ʵ���Ǹõ㣩�ľ���
 */
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAX_V 1000
using namespace std;

int V, E;
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
int used[MAX_V];

int prim()
{
    fill(mincost, mincost + MAX_V, INF);
    fill(used, used + MAX_V, false);
    int res = 0;
    mincost[0] = 0;
    while(true) {
        int v = -1;
        for(int u = 0; u < V; u++) {
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }
        if(v == -1) break;
        used[v] = true;
        res += mincost[v];
        for(int u = 0; u < V; u++) {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}

void solve()
{
    int ans;
    ans = prim();
    printf("%d\n", ans);
}

int main()
{
    fill(cost[0], cost[0] + MAX_V * MAX_V, INF);
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        cost[s][t] = cost[t][s] = c;
    }
    solve();
    return 0;
}

/* 
input
7 9
0 1 10
0 2 2
1 3 5
2 3 7
2 4 1
2 5 3
3 5 1
3 6 8
5 6 5
*/