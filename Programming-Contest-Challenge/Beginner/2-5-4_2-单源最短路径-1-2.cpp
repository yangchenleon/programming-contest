/* 
 * Bellman-Ford�㷨
 * ֮ǰ�ӱߵĽǶ���ƴ洢�ṹ�ģ�Ϊ��ͳһ�������дһ��
 * �����ǿ��ԣ���������֮ǰ�ĸ����ֱ��
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
#define MAX_V 1000
using namespace std;

struct edge {int to, cost;};
vector<edge> G[MAX_V];
int d[MAX_V];
int E, V;

void shortest_path(int s) // ���Ӷ���s���������е����̾���
{
    fill(d, d + V, INF);
    d[s] = 0;
    while(true) {
        bool update = false;
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < G[i].size(); j++) {
                edge e = G[i][j];
                if(d[i] != INF && d[e.to] > d[i] + e.cost) {
                    d[e.to] = d[i] + e.cost;
                    update = true;
                }
            }
        }
        if(!update) break;
    }
}

void solve()
{
    shortest_path(0);
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