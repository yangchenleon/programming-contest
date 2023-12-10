/* 
 * 原先基础上引入优先队列，在寻找最小和次小的时间复杂度降低为logn
 * 一定要注意要用lld输出
 */
#include <cstdio>
#include <vector>
#include <queue>
#define MAX_N 20000
using namespace std;

typedef long long ll;
int N;
int L[MAX_N];

void solve()
{
    ll ans = 0;
    priority_queue<int, vector<int>, greater<int> > que; // type：数据类型；container：实现优先队列的底层容器；function：元素之间的比较方式
    for(int i = 0; i < N; i++) {
        que.push(L[i]);
    }

    while(que.size() > 1) {
        int l1, l2;
        l1 = que.top(), que.pop();  
        l2 = que.top(), que.pop();

        ans += l1 + l2;
        que.push(l1 + l2);
    }
    printf("%lld\n", ans);
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }
    solve();
    return 0;
}

/* 
input
3
8 5 8
*/