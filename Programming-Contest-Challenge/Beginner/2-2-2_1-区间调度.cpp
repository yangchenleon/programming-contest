/* 
 * 给定数个任务的开始和结束时间，求最多能完成几项任务
 * 
 * 贪心策略是选择最早结束的任务，直观解释是结束越早可选工作就越多
 * 不过还是没有完全理解如何证明
 * 
 * 技巧：sort是默认参照第一个关键字升序排列，懒得写cmp，读取时就把结束时间读到第一个关键字，
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int N;
pair<int, int> work[MAX_N];

void solve()
{
    int ans = 0, t = 0; // 记录当前结束时间
    sort(work, work + N);

    for(int i = 0; i < N; i++) {
        if(work[i].second > t) {
            ans++;
            t = work[i].first;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &work[i].second, &work[i].first);
    }
    solve();
    return 0;
}

/* 
input
5
1 3
2 5
4 7
6 9
8 10
*/