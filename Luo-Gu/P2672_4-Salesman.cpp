/* 
 * 题目简述：给出N个住户的距离和代价，一米累计一疲劳，销售也累计代价疲劳，求来回一趟销售X用户的最大疲劳值
 * 
 * 解题思路：贪心，（暂时不考虑往返路程）依次选疲劳值最大的，不然就选路径代价远大于销售的代价的。
 * 于是有决策max(sum[i] + q[i], sum[i-1] + h[i])，前i户销售疲劳+路程，或前i-1户销售疲劳+后i户中总疲劳最大
 * 
 * 解题方法是理解了，但是还是不知其证明过程，以及为什么这么想的；
 * 好像还有其他优先队列、线段树的做法，不过不去研究了，不过收藏了
 * 还有就算知道方法，居然也写了好了，MD因为很多前缀和相关数组从1开始，
 * 改了半天一直以为是数组的问题，结果是sort的原因，范围光改前面没改后面
 */
#include <iostream>
#include <algorithm>
#define MAX_N 100005
using namespace std;

int N;
struct node{
    int d, a;
} p[MAX_N];
int sum[MAX_N], q[MAX_N], h[MAX_N];

bool cmp(node p1, node p2) {return p1.a > p2.a;}

void solve()
{
    int res;
    sort(p + 1, p + N + 1, cmp);
    for(int i = 1; i <= N; i++) {
        int j = N + 1 - i;
        sum[i] = sum[i-1] + p[i].a; // 疲劳值的前缀和
        q[i] = max(q[i-1], 2 * p[i].d); // 访问前i户所需的往返路程，算其中最大的
        h[j] = max(h[j+1], 2 * p[j].d + p[j].a); // 表示剩下j...N中贡献最大的一家，其路程必定是选定中最大
    }
    for(int i = 1; i <= N; i++) {
        res = max(sum[i] + q[i], sum[i-1] + h[i]);
        cout<<res<<endl;
    }
}

int main()
{
    cin>>N;
    for(int i = 1; i <= N; i++) cin>>p[i].d;
    for(int i = 1; i <= N; i++) cin>>p[i].a;
    solve();
    return 0;
}


/*
input
5
1 2 2 4 5
5 4 3 4 1

output
12
17
21
24
27
*/