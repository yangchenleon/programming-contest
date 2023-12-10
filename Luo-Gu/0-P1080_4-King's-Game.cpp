/* 
 * 题目简述：国王在首位，n位大臣左右手均写数字，第i位达成获得金币：前面所有人的左手乘积/本人右手，向下取整，令金币最多的人尽可能少
 * 
 * 解题思路：就是贪心，我自己也猜出来了，就是按照左右手乘积大小排序（乘积尽快小，然后除数到后面应该越来越大），虽然还是不知道为什么
 * 但是是做不出来的，因为a的范围10000，乘积就很大很大，是高精度问题，不会处理，详见python
 */
#include <iostream>
#include <algorithm>
#define MAX_N 1005
using namespace std;

int n;
struct node {
    int a, b;
} p[MAX_N];

bool cmp(node p1, node p2) {return p1.a * p1.b <  p2.a * p2.b;}

void solve()
{
    int sum = 1, mx = -1;
    sort(p + 1, p + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        sum *= p[i-1].a;
        mx = max(mx, sum / p[i].b);
    }
    cout<<mx;
}

int main()
{
    cin>>n;
    for(int i = 0; i <= n; i++) {
        cin>>p[i].a>>p[i].b;
    }
    solve();
    return 0;
}

/* 
input
3 
1 1 
2 3 
7 4 
4 6 
*/