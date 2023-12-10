#include <stdio.h>
#include <string.h>

int mat[11][11], n, num, ma;
bool visited[11];

void dfs(int x)
{
    if (num == n && mat[0][x]) {
        ma++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (mat[x][i] && visited[i] == false) {
            visited[i] = true;
            num++;
            dfs(i);
            num--;
            visited[i] = false;
        }
    }
}
int main()
{
    int t, m, x, i, j;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(mat, 0, sizeof(mat));
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &m);
            for (j = 1; j <= m; j++) {
                scanf("%d", &x);
                mat[i][x] = 1;
                mat[x][i] = 1;
            }
        }
        num = 0;
        ma = 0;
        dfs(0);
        printf("%d\n", ma);
    }
    return 0;
}