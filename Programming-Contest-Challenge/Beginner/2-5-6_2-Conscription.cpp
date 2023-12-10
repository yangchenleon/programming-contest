/* 问题描述：征兵要女N人，男M人， 每一个人要花费10000， 但是男女之间关系亲密，则可少花已经招募人中最大亲密值
 * 
 * 解题子图：转化为最小生成树，题中要求是最大权值树，将权值转化为负值即可成为最小生成树
 * 
 * 妈的烦死了，怎么就这么难ac，poj太老了，很多语法都不支持，改起来很烦，不过还是我的问题，要用lld输出，以及并查集大小不够
 */

#include <cstdio>
#include <algorithm>
#include "UFSet.h"
#define MAX_R 50000 // 最多关系数
#define MAX_N 10000 // 男女分别最多人数
using namespace std;

struct edge {int from, to, cost;};
edge es[MAX_R];
int x[MAX_N], y[MAX_N], d[MAX_R]; // 为了区分男女，设置xy，不过在本题中没有实际意义
const int base = 10000;
int M, N, R;

bool cmp(const edge &e1, const edge &e2)
{
    return e1.cost < e2.cost;
}

int kruskal()
{
    init(N + M);
    sort(es, es + R, cmp);
    int res = 0;
    for(int i = 0; i < R; i++) {
        edge e = es[i];
        if(!same(e.from, e.to)) {
            unite(e.to, e.from);
            res += e.cost;
        }
    }
    return res;
}

void solve()
{
    long long  ans = base * (M + N) + kruskal();
    printf("%lld\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &N, &M, &R);
        for(int i = 0; i < R; i++) {
            scanf("%d %d %d", &x[i], &y[i], &d[i]); 
            es[i] = (edge){x[i], N+y[i], -d[i]}; // 男女不区分，女从男(N)后计数
        }
        solve();
    }
    return 0;
}
/* 
input
2
5 5 8
4 3 6831
1 3 4583
0 0 6592
0 1 3063
3 3 4975
1 3 2049
4 2 2104
2 2 781
5 5 10
2 4 9820
3 2 6236
3 1 8864
2 4 8326
2 0 5156
2 0 1463
4 1 2439
0 4 4373
3 4 8889
2 4 3133
*/

