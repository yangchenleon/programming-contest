/* 
 * 埃式筛法：对许多素数进行素性测试，就是数范围内素数个数
 * 
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 1000000
using namespace std;

int n;
int prime[MAX_N]; // 存储素数
bool is_prime[MAX_N];

int sieve(int n)
{
    int p = 0; // 第p个素数
    fill(is_prime, is_prime + n, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 0; i <= n; i++) {
        if(is_prime[i]) {
            prime[p++] = i;
            for(int j = 2 * i; j <= n; j += i) is_prime[j] = false; // 素数的倍数一定不是素数
            //for(int j = 2; i * j <= n; j++) is_prime[i * j] = false; // 感觉这个更直观
        }
    }
    return p; // 由于从0开始，这里的p就是素数的个数
}

void solve()
{
    int ans = sieve(n);
    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &n);
    solve();
    return 0;
}

/* 
input1
11

input2
1000000
*/