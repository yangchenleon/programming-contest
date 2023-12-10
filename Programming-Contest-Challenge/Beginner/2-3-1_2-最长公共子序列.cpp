/* 
 * ���⣬�ҵ������ַ�����Ĺ������֣�
 * i, j �ֱ��ʾ�����ַ����ĵڼ����ַ�����dp[i][j]��ʾǰij����󹫹����� 
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 100
using namespace std;

int n, m;
char s[MAX_N];
char t[MAX_N];
int dp[MAX_N+1][MAX_N+1];

void solve()
{
    memset(dp, 0, sizeof(dp));
    for(int i = 0;i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}

int main()
{
    char* tmp;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    scanf("%s", t);
    solve();
    return 0;
}

/* 
input
4 4
abcd
bcde
*/