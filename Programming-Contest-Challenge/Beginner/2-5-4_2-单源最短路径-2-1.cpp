/* 
 * Dijkstra�㷨
 * ǰ���ǲ��ܴ��ڸ��ߣ���δȷ�ϵ���ѡ����̵�·��
 * �������Ѿ�����ø����ɴ�ĵ����·������������ѡ��С����Ϊȷ�ϵ㣩
 * ������V�����㣬����ÿ����������V��ʱ��Ѱ����̵��½ڵ��Լ�����·��������ʱ�临�Ӷ���V*V
 * ʹ���ڽӱ�Ļ�������·����ʱ����E��ֻ��������ڼ�¼��Ԥ�������ļ��ɣ���
 * �������¶��㻹����Ҫ����ÿ���������ѡ��Ҳ������V����˸��Ӷ�û�仯
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