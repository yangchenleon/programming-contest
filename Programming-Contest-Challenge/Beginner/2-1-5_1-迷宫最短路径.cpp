/* 
 * һ��n*m���Թ�������㵽�յ�����·��
 * ���������������Զ������˳������������������������·��
 * �ö�����ʵ�֣�����d��ʾ����õ��������룬��ʼΪINF��û�з��ʹ�����INF
 * 
 * Ҫ��&���ɣ���pair<int, int>��ʾһ���㣻�����������ʾ4�������ƶ�������������ֻ��һ��ѭ�����У�
 * ע��INF����������Ҫ������ڣ�ֻ�ܰ��ַ�����Ҫ�����з��ͺܷ�
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
        if(p.first == gx && p.second == gy) break; // ����
        for(int i = 0; i < 4; i++) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M) {
                if(maze[nx][ny] != '#' && d[nx][ny] == INF) {
                    que.push(P(nx, ny));
                    d[nx][ny] = d[p.first][p.second] + 1; // ��Զ������ÿһ�����Χ��ض��������
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