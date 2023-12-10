/* ��������������ҪŮN�ˣ���M�ˣ� ÿһ����Ҫ����10000�� ������Ů֮���ϵ���ܣ�����ٻ��Ѿ���ļ�����������ֵ
 * 
 * ������ͼ��ת��Ϊ��С������������Ҫ�������Ȩֵ������Ȩֵת��Ϊ��ֵ���ɳ�Ϊ��С������
 * 
 * ��ķ����ˣ���ô����ô��ac��poj̫���ˣ��ܶ��﷨����֧�֣��������ܷ������������ҵ����⣬Ҫ��lld������Լ����鼯��С����
 */

#include <cstdio>
#include <algorithm>
#include "UFSet.h"
#define MAX_R 50000 // ����ϵ��
#define MAX_N 10000 // ��Ů�ֱ��������
using namespace std;

struct edge {int from, to, cost;};
edge es[MAX_R];
int x[MAX_N], y[MAX_N], d[MAX_R]; // Ϊ��������Ů������xy�������ڱ�����û��ʵ������
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
            es[i] = (edge){x[i], N+y[i], -d[i]}; // ��Ů�����֣�Ů����(N)�����
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

