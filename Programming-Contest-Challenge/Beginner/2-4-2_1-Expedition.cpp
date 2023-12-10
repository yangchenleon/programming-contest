/* 
 * 1. 优先队列：插入数值；取出最小的数值并删除
 * STL里有prioroty_queue就是优先队列（不过是取出最大值），可有堆实现
 * 
 * 2. 堆：儿子的值一定不小于父亲的值；
 * 操作=插入数（从末尾插入不断上升）+取出最小值（交换首尾元素并调整），复杂度都是nlogn堆
 * 在HEAP.h中有实现
 * 
 * 问题描述：卡车有P单位油，行驶L公里，每公里消耗一单位油，
 * 路上n个加油站，每个距离起点A距离，提供最多B汽油，问能否抵达终点
 * 
 * 我自己写的：消耗当前油后加油，是否能到达目的地
 * 
 * 官方版本：是否能经过每一个加油站
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX_N 10000
#define MAX_L 1000000
#define MAX_P 1000000
using namespace std;

int N, L, P;
int A[MAX_N+1];
int B[MAX_N+1];

void solve()
{
    priority_queue<int> que;
    
    int ans = 0, pos = 0, tank = 0;
    int i = 0;
    que.push(P);
    while(!que.empty()) {
        if(pos >= L) break;
        pos += que.top();
        que.pop();
        ans++;
        while(i <= pos) {
            que.push(B[i++]);
        }
    }
    if(pos >= L) printf("%d\n", ans - 1); // 因为把初始油也算上了，故要减一
    else printf("%d\n", -1);

    while(!que.empty()) que.pop(); 
    A[N] = L, B[N] = 0;
    ans = 0, pos = 0,tank = P;
    for(int i = 0; i <= N; i++) {
        int d = A[i] - pos; // 到下一个加油站的距离
        while(tank - d < 0) {   // 不够就加到够
            if(que.empty()) {
                puts("-1");
                return;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d%d%d", &N, &L, &P);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &A[i], &B[i]);
    }
    solve();
    return 0;
}

/* 
input
4 25 10
10 10
14 5
20 2
21 4
*/