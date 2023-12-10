/* 
 * 题目概述：有n个武将，两两有默契度，我和机器依次选武将，机器每次总会选择我手上能构成最大默契的武将
 * 最后我和机器进行2v2比赛，求问是否能赢，若能赢并输出最大武将默契度
 * 
 * 解题思路：贪心，每次选次大的武将，机器每次拿最大的，意味着他也无法拿出最大的默契度
 * 那就取次大，既然他无法出最大，那我就是最大，因此人类永远会赢。
 * 注意是以行为单位取次大，因为是针对某一个武将选次大，即每行选一个；而非全局次大，
 * 全局次大可以是某行最大，这个武将组合是无法取到的；可以设置是否选过不过没必要。
 */
#include <iostream>
#include <algorithm>
#define MAX_N 505
using namespace std;

int N;
long long a[MAX_N][MAX_N];

void solve()
{
    long long res = -1;
    for(int i = 0; i < N; i++) {
        long long mx1 = -1, mx2 = -1;
        for(int j = 0; j < N; j++) {
            if(a[i][j] > mx1) {
                mx2 = mx1;
                mx1 = a[i][j];
            } else if(a[i][j] > mx2) {
                mx2 = a[i][j];
            }
        }
        res = max(res, mx2);
    }
    cout<<'1'<<endl;
    cout<<res<<endl;
}

int main()
{
    cin>>N;
    long long res = 0;
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - 1 - i; j++) {
            cin>>a[i][i+1+j]; // i+1表示i的下一个武将，j表示偏移量
            a[i+1+j][i] = a[i][i+1+j];            
        }    
    }
    solve();
    return 0;
}

/* 
input
8 
42 24 10 29 27 12 58 
31 8 16 26 80 6 
25 3 36 11 5 
33 20 17 13 
15 77 9 
4 50 
19 
*/