/* 
 * �ڱ��������������ÿ����Ʒ�����ö��
 * �Ƶ�ʽΪd[i+1][j] = max{dp[i][j-k*w[i]]+k*v[i]}
 * �����˲������˺Ͱ�����k�������ֻҪ����װ���£�
 * ��ǿ�汾��d[i+1][j]��k���������k���Ȳ�ѡ����d[i+1][j-w[i]]��k-1�����������һ����
 * �������Ϊ��j�����Ƿ����װ��i��
 * ͬ���ɸ�������ʵ�־���
 * ��Ϊ֮�漰��dp[i] �� dp[i+1]�����ǿ������������
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 100
using namespace std;

int n, W;
int w[MAX_N];
int v[MAX_N];
int dp[MAX_N+1][MAX_N+1];
int dp2[MAX_N+1];
int dp3[2][MAX_N+1];

void solve()
{
    
    memset(dp, 0, sizeof(dp)); // 1. ����
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= W; j++) { // ע������j��Ҫȡ��W�ģ�i����Ϊi+1�Ĵ��ڲ���ȡ��
            for(int k = 0; k * w[i] <= j; k++) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-k*w[i]] + k*v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
   
    memset(dp, 0, sizeof(dp)); // 2. ��ǿ��
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= W; j++) {
            if(j < w[i]) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
   
    memset(dp2, 0, sizeof(dp2)); // 3. �������龫���
    for(int i = 0; i < n; i++) {
        for(int j = w[i]; j <= W; j++) {
            dp2[j] = max(dp2[j], dp2[j-w[i]] + v[i]);
        }
    }
    printf("%d\n", dp2[W]);
    
    memset(dp3, 0, sizeof(dp3)); // 4. ѭ�����ã�����һ�ֲ�ࣩ
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= W; j++) {
            if(j < w[i]) {
                dp3[(i+1)&1][j] = dp3[i&1][j]; // &1�ж���ż������1ż��0
            } else {
                dp3[(i+1)&1][j] = max(dp3[i&1][j], dp3[(i+1)&1][j-w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp3[n&1][W]);
}

int main()
{
    scanf("%d%d", &n, &W);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }
    solve();
    return 0;
}

/* 
input
3 7
3 4
4 5
2 3
*/