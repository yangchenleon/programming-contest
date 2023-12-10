/* 
 * Bellman-Ford算法
 * 对于每个点，根据到达其的每条边反复更新到达某点的最短距离，直到没有更新变化
 * 可以解决负数权值，但出现负环（一圈的权值和小于0）则无法处理，不过可以检测
 * 最短路径不会经过同一个顶点2次，即最多通过V-1条边，由此检测负环
 * 这里我觉得该补充一句，通过证明，可知每一次迭代至少确定一个顶点的最短路径
 * 
 * 本题中边设计成有向的，对于无向图一条边要当作两条边来看，因此
 * scanf("%d %d %d", &es[i].from, &es[i].to, &es[i].cost);这样是不行的
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
#define MAX_E 1000
#define MAX_V 1000
using namespace std;

struct edge {int from, to, cost;};
edge es[MAX_E];

int d[MAX_V];
int E, V;


void shortest_path(int s) // 求解从顶点s出发到所有点的最短距离
{
    fill(d, d + V, INF);
    d[s] = 0;
    while(true) {
        bool update = false;
        for(int i = 0; i < E; i++) {
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
    }
}

bool find_negative_loop() // 如果返回true则存在负图
{
    memset(d, 0, sizeof(d));
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < E; j++) {
            edge e = es[j];
            if(d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if(i == V - 1) return true; // 如果第V次仍然更新了，则存在负图（就是V-1次循环应该不会进入到该条件判断）
            }
        }
    }
    return false;
}

void solve()
{
    
    if(find_negative_loop()) printf("存在负环");
    else {
        shortest_path(0);
        printf("%d\n", d[V-1]);
    }
}

int main()
{
    scanf("%d %d", &V, &E);
    E = E * 2;
    for(int i = 0; i < E; i++) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        es[i].from = es[i+1].to = s;
        es[i].to = es[i+1].from = t;
        es[i].cost = es[i+1].cost = c;
        i++;
        //
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