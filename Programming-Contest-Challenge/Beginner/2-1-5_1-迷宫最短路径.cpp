/* 
 * 一个n*m的迷宫，求起点到终点的最短路径
 * 宽度搜索，按照由远及近的顺序进行搜索，很容易来求最短路径
 * 用队列来实现，设置d表示到达该点的最近距离，初始为INF，没有访问过就是INF
 * 
 * 要点&技巧：用pair<int, int>表示一个点；用两个数组表示4个方向移动向量，这样就只用一个循环就行；
 * 注意INF不溢出；妈的要读出入口，只能按字符读，要处理换行符就很烦
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
#define MAX_N 100
#define MAX_M 100
using namespace std;

int N, M;
char maze[MAX_N][MAX_M];
int d[MAX_N][MAX_M];
int sx, sy, gx, gy;
typedef pair<int ,int> P;

int bfs()
{
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    queue<P> que;
    fill(d[0], d[0] + MAX_N * MAX_M, INF);
    d[sx][sy] = 0;

    que.push(P(sx, sy));
    while(!que.empty()) {
        P p = que.front(); que.pop();
        if(p.first == gx && p.second == gy) break; // 出口
        for(int i = 0; i < 4; i++) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M) {
                if(maze[nx][ny] != '#' && d[nx][ny] == INF) {
                    que.push(P(nx, ny));
                    d[nx][ny] = d[p.first][p.second] + 1; // 由远及近，每一点的周围点必定是最近的
                }
            }
        }
    }
    return d[gx][gy];
}

void solve()
{
    int res = bfs();
    printf("%d\n", res);
}

int main()
{
    scanf("%d%d\n", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%c", &maze[i][j]);
            if(maze[i][j] == 'S') {sx = i; sy = j;}
            if(maze[i][j] == 'G') {gx = i; gy = j;}
        }
        getchar();
    }
    solve();
    return 0;
}

/* input
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/