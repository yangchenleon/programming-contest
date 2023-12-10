/* 
 * ��һ������������������������У�ֻҪ��i<j �� a[i]<a[j]����Ҫ������
 * 
 * һ�㷽�������ĩβԪ��ʱ��󳤶�
 * 
 * ��һ��˼·�������ͬ������С��ĩβԪ��
 * 
 * ��һ���Ľ����׵�����dp����һ���ǵ����ģ�����������ʵ���Ͼ����ҵ�������a[j]����Ȼ��������һλ
 * ����ö��֣����ӶȽ���nlogn
 */
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAX_N 1000
using namespace std;

int n;
int a[MAX_N];
int dp[MAX_N]; // ��a[i]��β��������г���

void solve()
{
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) { // �Ҹպñ�a[i]С����
            if(a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    printf("%d\n", res);

    res = 0;
    fill(dp, dp + n, INF);
    for(int i = 0; i < n; i++) { // ����ÿ��Ԫ��
        for(int j = 0; j < i; j++) { // i+1��Ϊ����
            if(a[i] > dp[j-1] || j == 0) {
                dp[j] = min(a[i], dp[j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(dp[i] < INF) {
            res = i + 1;
        }
    }
    printf("%d\n", res);

    fill(dp, dp + n, INF);
    for(int i = 0; i < n; i++) {
        *lower_bound(dp, dp + n, a[i]) = a[i]; // ���ö��������ҳ�����a��>=k����Сa[i]�ĵ�ַ�����ڵ���k���½죩
    }
    printf("%d\n", lower_bound(dp, dp + n, INF) - dp);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < 9; i++) {
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}

/* 
input
5
4 2 3 1 5
*/
