/* 
 * 在前面的基础上，引入优先队列使查找下一个顶点 
 */
#include <cstdio>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define MAX_V 1000
using namespace std;

struct edge{int to, cost;};
typedef pair<int, int> P; // first是最短距离，second是顶点编号

int V, E;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que; // 堆将按照first从小到大顺序取出
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
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
    scanf("%d %d", &V, &E); 
    for(int i = 0; i < E; i++) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        G[s].push_back({t, c});
        G[t].push_back({s, c});
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