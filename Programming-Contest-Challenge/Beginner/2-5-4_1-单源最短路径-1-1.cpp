/* 
 * Bellman-Ford�㷨
 * ����ÿ���㣬���ݵ������ÿ���߷������µ���ĳ�����̾��룬ֱ��û�и��±仯
 * ���Խ������Ȩֵ�������ָ�����һȦ��Ȩֵ��С��0�����޷������������Լ��
 * ���·�����ᾭ��ͬһ������2�Σ������ͨ��V-1���ߣ��ɴ˼�⸺��
 * �����Ҿ��øò���һ�䣬ͨ��֤������֪ÿһ�ε�������ȷ��һ����������·��
 * 
 * �����б���Ƴ�����ģ���������ͼһ����Ҫ�������������������
 * scanf("%d %d %d", &es[i].from, &es[i].to, &es[i].cost);�����ǲ��е�
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


void shortest_path(int s) // ���Ӷ���s���������е����̾���
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

bool find_negative_loop() // �������true����ڸ�ͼ
{
    memset(d, 0, sizeof(d));
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < E; j++) {
            edge e = es[j];
            if(d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if(i == V - 1) return true; // �����V����Ȼ�����ˣ�����ڸ�ͼ������V-1��ѭ��Ӧ�ò�����뵽�������жϣ�
            }
        }
    }
    return false;
}

void solve()
{
    
    if(find_negative_loop()) printf("���ڸ���");
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