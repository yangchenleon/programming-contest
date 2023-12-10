/* 
 * Dijkstra算法
 * 前提是不能存在负边，在未确认点中选出最短的路径
 * （事先已经计算好各个可达的的最短路径，再在其中选最小的作为确认点）
 * 共更新V个顶点，更新每个顶点消耗V的时间寻找最短的新节点以及更新路况，所以时间复杂度是V*V
 * 使用邻接表的话，更新路况的时间变成E（只需操作表内记录的预期相连的即可），
 * 但是找新顶点还是需要遍历每个顶点从中选择也是消耗V，因此复杂度没变化
 */
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAX_V 100
using namespace std;

int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V, E;

void dijkstra(int s)
{
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0;
    while(true) {
        int v = -1;
        for(int u = 0; u < V; u++) {
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;     
        }

        if(v == -1) break;
        used[v] = true;

        for(int u = 0; u < V; u++) {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
}

void solve()
{
    dijkstra(0);
    printf("%d\n", d[V-1]);
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
7 10
0 1 2
0 2 5
1 2 4
1 3 6
2 3 2
1 4 10
3 5 1
4 5 3
4 6 5
5 6 9
*/