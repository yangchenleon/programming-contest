/* 
 * 给定整数a,b，求[a, b)内有多少素数
 * b以内的最小质因子一定不超过根号b，有了a~根号b的质数范围，
 * 就可更具筛法从a~b中筛选
 */
#include <cstdio>
#include <algorithm>
#define MAX_L 1000000
#define MAX_SQRT_B 1000000 // 对B开根号
using namespace std;

typedef long long ll;
ll a, b;
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

void segment_sieve(ll a, ll b)
{
    for(int i = 0; (ll)i * i < b; i++) is_prime_small[i] = true;
    for(int i = 0; i < b - a; i++) is_prime[i] = true;

    for(int i = 2; (ll)i * i < b; i++) {
        if(is_prime_small[i]) { // 记住i的值代表一个素数
            for(int j = 2 * i; (ll)j * j < b; j += i) is_prime_small[j] = false;
            for(ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) { // 这里(a+i-1)/i是为了保证从a这个数开始筛掉[带进入嘛，第一个j=a+1]
                is_prime[j - a] = false; // 这里指从a开始第j个数是非素数
            }
        }
    }
}

void solve()
{
    int ans = 0;
    segment_sieve(a, b);
    for(int i = 0; i < b - a; i++) {
        if(is_prime[i]) ans++;
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%lld%lld", &a, &b);
    solve();
    return 0;
}

/* 
input1
22 37

input2
22801763489 22801787297
*/