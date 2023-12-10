/* 
 * 对于任意1<x<n都有x^n≡x(mod n)成立的合数称为Carmichael Number，对于给定整数，判断是否是CN
 * 快速幂：反复平方法
 * 
 * 对于该问题，没有具体研究，不过好像卡迈克尔数前提是不是素数
 */
#include <cstdio>
#define MAX_N 65000
using namespace std;

typedef long long ll;
int n;

bool is_prime(int n) // 素性测试
{
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false; 
    }
    return n != 1; // 1是例外
}

ll mod_pow1(ll x, ll n, ll mod)
{
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % mod; // 如果二进制最低为为1（奇数）
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll mod_pow2(ll x, ll n, ll mod) 
{
    if(n == 0) return 1;
    ll res = mod_pow2(x * x % mod, n / 2, mod);
    if(n & 1) res = res * x % mod;
    return res;
}

void solve()
{
    bool flag = true;
    for(int i = 2; i < n; i++) {
        if(mod_pow1(i, n, n) != i) {
            flag = false; 
            break;
        }       
    }
    if(!is_prime(n) && flag) printf("Yes\n");
    else printf("No\n");
    
}

int main()
{
    scanf("%d", &n);
    solve();
    return 0;
}