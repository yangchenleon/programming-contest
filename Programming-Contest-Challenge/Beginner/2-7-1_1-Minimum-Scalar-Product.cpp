/* 
 * 题目描述：有两个向量，允许交换内部顺序，求最小内积
 * 
 * 解题思路：直接贪心，结果是对的，不知道怎么证明
 * 注意容易溢出，一定要存储为long long
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 850
using namespace std;

int n;
int v1[MAX_N], v2[MAX_N];

void solve()
{
    long long res = 0;
    sort(v1, v1 + n);
    sort(v2, v2 + n);
    for(int i = 0; i < n; i++) {
        res += v1[i] * v2[n-1-i];
    }
    printf("%lld\n", res);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &v1[i], &v2[i]);
    }
    solve();
    return 0;
}

/*
input1
3
1 -2
3 4
-5 1

input2
5
1 1
2 0
3 1
4 0
5 1
*/