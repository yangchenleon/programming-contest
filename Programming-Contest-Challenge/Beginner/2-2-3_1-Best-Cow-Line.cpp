/* 
 * 一个长n的字符串从头或尾拉一个字符到另一个字符数组，使其构成最短字典序（strcmp的比较方法，a<b）
 * 
 * 左右取最小的，如果两端相同则要继续向中间比较直到遇到较小者，使小端尽早露出来
 */
#include <cstdio>
#define MAX_N 2010
using namespace std;

int N;
char S[MAX_N]; // 如果取2000，应该是MAX_N+1, 为\0留空间

void solve()
{
    int l = 0, r = N - 1;
    while(l <= r) {
        bool left = false;
        for(int i = 0; l + i <= r; i++) { // 我觉得这里循环次数太多了，到l+i<=r-i就够了
            if(S[l+i] < S[r-i]) {
                left = true;
                break;
            } else if(S[l+i] > S[r-i]) {
                left = false;
                break;
            }
        }
        if(left) printf("%c", S[l++]);
        else printf("%c", S[r--]);
    }
    printf("\n");
}

int main()
{
    scanf("%d", &N);
    scanf("%s", S);
    solve();
    return 0;
}

/* 
input
7
bceaecb
*/