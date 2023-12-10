/* 
 * 有1、5、10、50、100、500面值的硬币多枚，要用这硬币支付A元，至少需要多少硬币（至少存在一种支付方案）
 * 
 * 根据直觉就是先付出最大面额，用完了就用小面额直到支付结束
 * 
 * 技巧：对于常量（如本体面额）就用const修饰
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};
long long C[6], A;

void solve()
{
    int ans;
    for(int i = 5; i >= 0; i--) {
        int t = min(C[i], A / V[i]);
        ans += t;
        A -= t * V[i];
    }
    printf("%d\n", ans);
}

int main()
{
    for(int i = 0; i < 6; i++) {
        scanf("%d", &C[i]);
    }
    scanf("%d", &A);
    solve();
    return 0;
}

/*
input 
3 2 1 3 0 2
620
*/