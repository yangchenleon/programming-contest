/* 
 * ʹ�����ȶ���ʵ��
 * ���ܵ����հ�֮ǰdjistra��д������Ϊ֮ǰ����½ڵ��ǵ����ģ������֮ǰ�Ľڵ�д����
 * ������п��ܻ�Ѷ̱��ظ����룬��Ҫ����used����Ƿ��Ѿ�������
 * дbug��ͬʱд��·����ԭ 
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
#define MAX_V 1000
using namespace std;

struct edge{int to, cost;};
typedef pair<int, int> P; // first����̾��룬second�Ƕ�����

int V, E;
vector<edge> G[MAX_V];
int mincost[MAX_V];
int prv[MAX_V];
bool used[MAX_V];

int prim()
{
    priority_queue<P, vector<P>, greater<P>> que;
    fill(mincost, mincost + V, INF);
    fill(used, used + MAX_V, false);
    fill(prv, prv + V, -1);
    mincost[0] = 0;
    que.push(P(0, 0));
    int res = 0;
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(used[v] || mincost[v] < p.first) continue;
        res += mincost[v];
        used[v] = true;
        for(int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if(!used[e.to] && mincost[e.to] > e.cost) {
                mincost[e.to] = e.cost;
                prv[e.to] = v;
                que.push(P(mincost[e.to], e.to));
            }
        }
    }
    return res;
}

void solve()
{
    int ans;
    ans = prim();
    printf("%d\n", ans);
    for(int i = 0; i < V; i++) {
        printf("%d->%d\n", prv[i]+1, i+1);
    }
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