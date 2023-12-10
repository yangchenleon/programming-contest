/* 
 * ������������n���������Ƿ���ǡ�ôճ�k
 * 
 * ����˼·��������ѧ�궯̬�滮��ͷ�����ģ���������ʵ�֣��������k̫���ˣ��ö�̬�Ի���̫��
 * ������������������ͺܺã���������û����ԭ·��
 * �Ҵ��ˣ�������̬�滮���û�ԭ·��
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 25
#define MAX_K 1000
using namespace std;

int n, k;
int a[MAX_N];
bool dp[MAX_N+1][MAX_K+1];
bool check[MAX_N];
int prv[MAX_N];

bool dfs(int i, int sum)
{
    if(i == n) return sum == k; // �Ѿ����������нڵ㣬�鿴�Ƿ����һ�����
    if(dfs(i + 1, sum)) return true; // ����a[i]
    if(dfs(i + 1, sum + a[i])) {chcek[i] = true;return true;}
    return false;
}

void solve()
{
    fill(prv, prv + n, -1);
    dp[0][0] = true; // ��̬�滮
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j - a[i] >= 0) {
                dp[i+1][j] = dp[i][j-a[i]] | dp[i][j];
                if(dp[i][j-a[i]]) prv[j] = j-a[i]; // ��¼��������ǰ����һ����
            } else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    if(dp[n][k]) printf("Yes\n");
    else printf("No\n");
    for(int t = k; t != 0; t = prv[t]) {
        printf("%d+", t-prv[t]);
    }
    printf("=%d\n", k);

    fill(check, check + n, false);
    bool ans = dfs(0, 0);
    if(ans) printf("Yes\n");
    else printf("No\n");
    for(int i = 0; i < n; i++) {
        if(check[i]) printf("%d+", a[i]);
    }
    printf("=%d\n", k);
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}
/* 
input1
4 11
1 2 4 7 

input2
4 15
1 2 4 7
*/