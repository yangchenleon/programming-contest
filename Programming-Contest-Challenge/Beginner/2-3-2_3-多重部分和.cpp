/* 
 * �ڲ��ֺͻ����ϣ��Բ�ͬ������������
 * ��n�����֣�ÿ��m�����ж��Ƿ����ѡ������ʹ��ǡ��ΪK
 * dp[i+1][j]��ʾǰi���ܷ�ϳ�j
 */
#include <cstdio>
#include <cstring>
#define MAX_N 100
#define MAX_K 100000
using namespace std;

int n, K;
int a[MAX_N];
int m[MAX_N];
bool dp[MAX_N+1][MAX_K+1];
int dp2[MAX_K+1];

void solve()
{
    dp[0][0] = true; // һ�㷨�����Ӷȴ󣬲��������
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= K; j++) {
            for(int k = 0; k <= m[i] && k * a[i] <= j; k++) {
                dp[i+1][j] |= dp[i][j-k*a[i]];
            }
        }
    }
    if(dp[n][K]) printf("Yes\n");
    else printf("No\n");

    memset(dp2, -1, sizeof(dp2)); // ����ֵת��Ϊ�õ�j�����i�����ĸ���+�����ظ�����
    dp2[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= K; j++) {
            if(dp2[j] >= 0) {
                dp2[j] = m[i];
            } else if(j < a[i] || dp2[j-a[i]] <= 0) { // �ߵ�����˵��ǰi-1�޷��ϳ�j����ô���Ե�i��;���������Ҫô���˳�����Ҫô�ټӾͲ�����
                dp2[j] = -1;
            } else {
                dp2[j] = dp2[j-a[i]] - 1; // ��������˴�����һ����i����Ʒ
            }
        }
    }
    if(dp2[K]) printf("Yes\n");
    else printf("No\n");
}

int main()
{
    scanf("%d%d", &n, &K);
    for(int i = i; i < n; i++) {
        scanf("%d%d", &a[i], &m[i]);
    }
    solve();
    return 0;
}

/* 
input
3 17
3 3
5 2
8 2
*/
