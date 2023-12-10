/* 
 * ����������R����·��N��·�ڣ�˫���Ҵζ̵�·����ͬһ���߿��Ծ������
 * 
 * ����˼·������Dijstra�㷨����¼���������·�������дζ�·��
 * ���������ȶ���ά�����·��������ͬʱ����ܵĴζ�·��������̻��̾͸������·����
 * �����������Ĵ��ڵ�ǰ�ζ�·��������С�����·����˵���������·������һ���ڵ�
 * 
 * acҲ�����⣬dist2[0] = 0�Ǵ�ģ���Ϊ��¼�Ĵζ̣�����˫��ĵ�����Ĵζ�Ӧ����һ���۷�·����
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