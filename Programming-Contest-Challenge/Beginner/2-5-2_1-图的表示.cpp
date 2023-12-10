/* 
 * 图的表示：邻接矩阵 和 邻接表
 * 邻接矩阵用二维数组表示，无向图中1表示存在边，对称；有向图中1表示从i到j存在一条边，不一定对称；
 * 若设置权值则将边修改为权值，不存在边则用INF表示；很快查找边的信息，但不适宜存储稀疏图
 * 邻接表存储空间小，但是实现较为复杂，需要通过遍历链表查询是否有边
 * 下为2中邻接表的实现方式
 */
#include <cstdio>
#include <vector>
#define MAX_V 1000
using namespace std;

vector<int> G1[MAX_V]; // 方法一
/* 边上有属性的情况
 * struct edge {int to, cost;};
 * vector<edge> G[MAX_V];
 */

struct vertex { // 方法二
    vector<vertex*> edge;
    /* 
     * 顶点的属性
     */
} G2[MAX_V];

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
    for(int i = 0; i < V; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        G1[s].push_back(t); // 方法一的操作
        G2[s].edge.push_back(&G2[t]); // 方法二的操作
        // G2[t].edge.push_back(&G[s]);
    }
    // 省略接下来的图的操作
}

/* 
input
3 3
0 1
0 2
1 2
*/
