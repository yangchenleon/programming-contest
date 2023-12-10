/* 
 * 问题描述给定一个0/1矩阵，只允许交换相邻两行，求化成下三角矩阵需要交换几次（保证能化成）
 * 
 * 解题思路：还是贪吃，距离目标的位置的行优先移动（不知道为啥）；只需记录该行末尾1的位置就能表示该行
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 45
using namespace std;

int n;
int a[MAX_N];

void solve()
{
    int res = 0;
    for(int i = 0; i < n; i++) { // 根据下三角矩阵特征，寻找符合a[j]<=i最近的一行pos行填入i行
        int pos = -1;
        for(int j = i; j < n; j++) {
            if(a[j] <= i) { // 本来==就行的，为什么呢，详见输入3
                pos = j;
                break;
            }
        }

        for(int j = pos; j > i; j--) {
            swap(a[j], a[j-1]);
            res++;
        }
    }
    printf("%d\n", res);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char tmp[n];
        a[i] = -1; // 全零情况
        scanf("%s", tmp); // 输入就是连着来的，很麻烦
        for(int j = 0; j < n; j++) {
            if(tmp[j] == '1') a[i] = j;
        }
    }
    solve();
    return 0;
}

/*
input1
2
10
11

input2
3
001
100
010

input3 
4
1110
1100
1100
1000
*/