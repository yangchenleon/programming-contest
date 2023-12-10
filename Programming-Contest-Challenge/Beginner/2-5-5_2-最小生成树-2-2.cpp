/* 
 * ��֮ǰbellmanfordһ�������Ϊ��ʹͼ�ṹ���ͳһ��û��Ч���ϵĸĽ�
 * �ڳ�ʼ�������Լ���������Ծ���ͽ���鷳������鷳���٣������еû�, ɵ��
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include "UFSet.h"
#define MAX_V 1000
using namespace std;

struct edge {int to, cost;};
vector<edge> G[MAX_V];
int V, E;

bool cmp(const edge &e1, const edge &e2) { // ����Ϊʲô����Ҫ��ȡ��ַ��
    return e1.cost < e2.cost;
}

int kruskal()
{
    for(int i = 0; i < V; i++) {
        sort(G[i].begin(), G[i].end(), cmp);
    }
    init(V);
    int res = 0;
    while(true) {
        bool update = false;
        int u = -1;
        for(int i = 0; i < V; i++) {
            if(G[i].size() && (u==-1 || G[i][0].cost < G[u][0].cost)) u = i;
        }
        if(u == -1) break;
        if(!same(u, G[u][0].to)) {
            unite(u, G[u][0].to);                
            res += G[u][0].cost;
            G[u].erase(G[u].begin());
            update = true;
        } else {
            G[u].erase(G[u].begin());
            continue;
        }
        if(!update) break;
    }
    return res;
}

void solve()
{
    int ans = kruskal();
    printf("%d\n", ans);
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