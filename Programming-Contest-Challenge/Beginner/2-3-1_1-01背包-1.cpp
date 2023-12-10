/* 
 * ֮ǰ��������ͬһ��ִ֧�������� 
 * �ڴ˻����ϼ�����仯���飬��DP
 * ��ת��Ϊ����ʽ���Ӷ��ö���ѭ��ʵ��
 * �������ظ�����һ������ʵ�֣��Ӻ���ǰ�޸ķ���ǰ������ݻ�Ӱ�쵽����ģ�������ʹ�ò����з��� 
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 100
using namespace std;

int n, W;
int w[MAX_N];
int v[MAX_N];
int dp[MAX_N+1][MAX_N+1]; // ���仯����
int dp2[MAX_N+1];

// �ӵ�i����Ʒ��ʼ��ѡ����С��j�Ĳ���
int rec(int i, int j)
{
    int res;
    if(i == n) {
        res = 0; // �Ѿ�û��ʣ����Ʒ��
    } else if(j < w[i]) { 
        res = rec(i+1, j); // �޷���ѡ�����Ʒ
    } else {
        res = max(rec(i+1, j), rec(i+1, j-w[i])+v[i]); // ��ѡ�Ͳ���ѡ�������������һ��
    }
    return res;
}

void solve()
{   
    memset(dp, -1, sizeof(dp)); // 1. ͨ�����仯����
    printf("%d\n", rec(0, W));

    memset(dp, 0, sizeof(dp)); // 2. ͨ������ʽ
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= W; j++) {
            if(j < w[i]) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
    
    memset(dp2, 0, sizeof(dp2)); // 3. ����������
    for(int i = 0; i < n; i++) {
        for(int j = W;j >= w[i]; j--) {
            dp2[j] = max(dp2[j], dp2[j-w[i]] + v[i]);
        }
    }
    printf("%d\n", dp2[W]);
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
4 5
2 3
1 2
3 4 
2 2
*/