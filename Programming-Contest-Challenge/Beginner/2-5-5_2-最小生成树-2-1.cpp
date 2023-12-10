/* 
 * Kruskal算法
 * 每次都取最小边，只要加入不成为圈
 * 虽然边的表示和bellman一样，但是由于算法这里不需要存储正反两遍
 */
#include <cstdio>
#include <algorithm>
#include "UFSet.h"
#define MAX_V 1000
#define MAX_E 1000
using namespace std;

struct edge{int u, v, cost;};

bool comp(const edge &e1, const edge &e2)
{
    return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

int kruskal()
{
    sort(es, es + E, comp);
    init(V);
    int res = 0;
    for(int i = 0; i < E; i++) {
        edge e = es[i];
        if(!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
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
        es[i].u = s;
        es[i].v = t;
        es[i].cost = c;
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