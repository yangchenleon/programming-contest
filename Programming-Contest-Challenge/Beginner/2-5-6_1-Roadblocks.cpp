/* 
 * 问题描述：R条道路，N个路口，双向，找次短的路径，同一条边可以经过多次
 * 
 * 解题思路：基于Dijstra算法，记录不仅是最短路径，还有次短路径
 * 还是用优先队列维护最短路径，不过同时存可能的次短路径，比最短还短就更新最短路径，
 * 当新挑出来的大于当前次短路径，但又小于最短路径，说明这是最短路径的吓一跳节点
 * 
 * ac也有问题，dist2[0] = 0是错的，因为记录的次短，且是双向的到达其的次短应该是一条折返路径。
 */
#include <cstdio>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define MAX_N 5010
#define MAX_R 100010
using namespace std;

typedef pair<int, int> P;
struct edge {int to, cost;};
vector<edge> G[MAX_N];
int dist[MAX_N];
int dist2[MAX_N];
int V, E;

void solve()
{
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist, dist + V, INF);
    fill(dist2, dist2 + V, INF);
    dist[0] = 0; // dist2[0] = 0;
    que.push(P(0, 0));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second, d = p.first;
        if(dist2[v] < d) continue;
        for(int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            int d2 = d + e.cost;
            if(d2 < dist[e.to]) {
                swap(dist[e.to], d2);
                que.push(P(dist[e.to], e.to));
            }
            if(d2 > dist[e.to] && d2 < dist2[e.to]) {
                swap(dist2[e.to], d2);
                que.push(P(dist2[e.to], e.to));
            }
        }
    }
    printf("%d\n", dist2[0]);
}

int main()
{
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        G[s-1].push_back({t-1, c});
        G[t-1].push_back({s-1, c});
    }
    solve();
    return 0;
}

/* 
input
4 4
1 2 100
2 3 250
2 4 200
3 4 100
*/