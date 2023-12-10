/* 
 * ����ͨ����ʹd[j]=d[k]+cost[k][j]ͨ����k�������j��ǰ��
 * Ҳ��������prev���飬�������·����ʱ���ϵ�ʽ���¼��ɸ���prev����
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
#define MAX_V 100
#define MAX_E 100
using namespace std;

int V, E;
int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int prv[MAX_V];

void dijkstra(int s)
{
    fill(used, used + V, false);
    fill(d, d + V, INF);
    fill(prv, prv + V, -1); // ��ʼ��
    d[s] = 0;
    while(true) {
        int v = -1; // ���������½ڵ�
        for(int u = 0; u < V; u++) {
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;     
        }
        if(v == -1) break;
        used[v] = true;
        for(int u = 0; u < V; u++) {
            if(d[u] > d[v] + cost[v][u]) { // ����ǰ���ڵ�
                d[u] = d[v] + cost[v][u];
                prv[u] = v;
            }
        }
    }
}

struct edge{int from, to, cost;};
edge es[MAX_E];

void BellmanFord(int s)
{
    fill(d, d + V, INF);
    fill(prv, prv + V, -1);
    d[s] = 0;
    while(true) {
        bool update = false;
        for(int i = 0; i < E; i++) {
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                prv[e.to] = e.from;
                update = true;
            }
        }
        if(!update) break;
    }
}

vector<int> get_path(int t)
{
    vector<int> path;
    for(; t != -1; t = prv[t]) {
        path.push_back(t);
    }
    reverse(path.begin(), path.end());
    return path;
}

void solve()
{
    dijkstra(0);
    printf("%d\n", d[V-1]);
    vector<int> path = get_path(6);
    for(int i = 0; i < path.size(); i++) {
        printf("%d%s", path[i], i == path.size()-1?"\n":"->");
    }

    BellmanFord(0);
    printf("%d\n", d[V-1]);
    path = get_path(6);
    for(int i = 0; i < path.size(); i++) {
        printf("%d%s", path[i], i == path.size()-1?"\n":"->");
    }
}

int main()
{
    fill(cost[0], cost[0] + MAX_V * MAX_V, INF);
    scanf("%d %d", &V, &E); E <<= 1;
    for(int i = 0; i < E; i++) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        cost[s][t] = cost[t][s] = c;
        es[i].from = es[i+1].to = s;
        es[i].to = es[i+1].from = t;
        es[i].cost = es[i+1].cost = c;
        i++;
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