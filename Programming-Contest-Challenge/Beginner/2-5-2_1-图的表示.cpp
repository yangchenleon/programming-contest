/* 
 * ͼ�ı�ʾ���ڽӾ��� �� �ڽӱ�
 * �ڽӾ����ö�ά�����ʾ������ͼ��1��ʾ���ڱߣ��Գƣ�����ͼ��1��ʾ��i��j����һ���ߣ���һ���Գƣ�
 * ������Ȩֵ�򽫱��޸�ΪȨֵ�������ڱ�����INF��ʾ���ܿ���ұߵ���Ϣ���������˴洢ϡ��ͼ
 * �ڽӱ�洢�ռ�С������ʵ�ֽ�Ϊ���ӣ���Ҫͨ�����������ѯ�Ƿ��б�
 * ��Ϊ2���ڽӱ��ʵ�ַ�ʽ
 */
#include <cstdio>
#include <vector>
#define MAX_V 1000
using namespace std;

vector<int> G1[MAX_V]; // ����һ
/* ���������Ե����
 * struct edge {int to, cost;};
 * vector<edge> G[MAX_V];
 */

struct vertex { // ������
    vector<vertex*> edge;
    /* 
     * ���������
     */
} G2[MAX_V];

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
    for(int i = 0; i < V; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        G1[s].push_back(t); // ����һ�Ĳ���
        G2[s].edge.push_back(&G2[t]); // �������Ĳ���
        // G2[t].edge.push_back(&G[s]);
    }
    // ʡ�Խ�������ͼ�Ĳ���
}

/* 
input
3 3
0 1
0 2
1 2
*/
