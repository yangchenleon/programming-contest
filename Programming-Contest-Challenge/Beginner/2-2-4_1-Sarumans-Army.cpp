/* 
 * ֱ������N���㣬��i��λ����x���ڵ�뾶R�ķ�Χ�ڱ���Ҫ�б�ǵ㣬��������Ҫ���ٱ�ǵ�
 * 
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 1000
using namespace std;

int N, R;
int X[MAX_N];

void solve()
{
    sort(X, X + N);
    int i = 0, ans = 0;
    while(i < N) {
        int s = X[i++];
        while(i < N && s + R >= X[i]) i++;
        int p = X[i-1];
        while(i < N && p + R >= X[i]) i++;
        ans++;
    }
    printf("%d", ans);
}

int main()
{
    scanf("%d%d", &N, &R);
    for(int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }
    solve();
    return 0;
}

/* 
input
6 10
1 7 15 20 30 50
*/