/* 
 * 直线上有N个点，点i的位置是x，在点半径R的范围内必须要有标记点，求至少需要多少标记点
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