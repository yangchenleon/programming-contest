/* 
 * 题目描述：给定最大重量，以及若干物品的重量，两两搭配，求最小搭配数量
 *
 * 解题思路：贪心就行（虽然不会证明），不过还是有点麻烦，主要就是边界条件设置上
 * 外层循环中，lr分别表示边界待判定的物品，最后可落到同一个物品或者最后恰好匹配，因此可重合
 * 内层循环中，从右向左测试是否能和l合并，直到不行了后说明r和l匹配，然后l++，r--表示对下一个l测试，同时匹配了res++
 */
#include <iostream>
#include <algorithm>
#define MAX_N 30005
using namespace std;

int w, n;
int a[MAX_N];

void solve()
{
    int res = 0;
    int l = 0, r = n - 1;
    while(l <= r) {
        while(l < r && a[l] + a[r] > w) { res++; r--;}
        l++; r--; res++;
    }
    cout<<res<<endl;
}

int main()
{
    cin>>w>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);
    solve();
    return 0;
}

/*
input
100 
5
90
90
90
90
90
*/