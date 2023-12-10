/* 
 * 有大小为n*m的园子，求有多少积水是连通的
 * 深度优先搜索，就是一旦出现满足条件的分支，
 * 就继续接着分支下去，直到进行不下去后返回到上一层分析另一条分支
 * 所采用的数据结构是栈，一般用递归调用实现
 */
#include <cstdio>
#define MAX_N 100
#define MAX_M 100
using namespace std;

int N, M;
char field[MAX_N][MAX_M];

void dfs(int x, int y)
{
    field[x][y] = '.';
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            int nx = x + dx, ny = y + dy;
            if(0 <= nx && nx < N && 0 <= ny && ny <= M) {
                if(field[nx][ny] == 'W') dfs(nx, ny);
            }
        }
    }
    return;
}

void solve()
{
    int res = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(field[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
        }
    }
    printf("%d\n", res);
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%s", &field[i]);
    }
    solve();
    return 0;
}

/* 
input
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W.
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
*/