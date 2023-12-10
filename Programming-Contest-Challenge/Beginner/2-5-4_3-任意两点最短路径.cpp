/* 
 * Floyd-Warshalls算法
 * 就是用动态规划，通过是否经过k点作为推导依据
 */
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAX_V 1000
using namespace std;

int d[MAX_V][MAX_V];
int V, E;

void warshall_floyd()
{
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void solve()
{
    warshall_floyd();
}

int main()
{
    scanf("%d %d", &V, &E);
    fill(d[0], d[0] + MAX_V * MAX_V, INF);
    for(int i = 0; i < V; i++) d[i][i] = 0;
    for(int i = 0; i < E; i++) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        d[s][t] = d[t][s] = c;
    }
    
    solve();
    int cnt;scanf("%d", &cnt);
    for(int i = 0; i < cnt; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        printf("%d\n", d[s][t]);
    }
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
1
0 6
*/