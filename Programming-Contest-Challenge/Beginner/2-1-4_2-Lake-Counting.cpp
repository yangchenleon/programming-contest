/* 
 * �д�СΪn*m��԰�ӣ����ж��ٻ�ˮ����ͨ��
 * �����������������һ���������������ķ�֧��
 * �ͼ������ŷ�֧��ȥ��ֱ�����в���ȥ�󷵻ص���һ�������һ����֧
 * �����õ����ݽṹ��ջ��һ���õݹ����ʵ��
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