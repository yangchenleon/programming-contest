/* 
 * ��n�����������Ʒ�����仮��Ϊ������m�飬������ַ���������ģM�Ľ����
 * ͨ�������Ƿ�պ���m����Ϊ���֣�ע���ǡ����������� 
 */
#include <cstdio>
#define MAX_N 1000
#define MAX_M 1000
#define M 10000; // ģ
using namespace std;

int n, m;
int dp[MAX_M+1][MAX_N+1]; // j��i���ָ���

void solve()
{
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(j - i >= 0) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % M;
            } else {
                dp[i][j] = dp[i-1][j]; //�������5���ֳɲ�����6���൱�ڷֳ�5
            }
        }
    }
    printf("%d\n", dp[m][n]);
}

int main()
{
    scanf("%d%d", &n, &m);
    solve();
    return 0;
}

/* 
input
4 3
*/