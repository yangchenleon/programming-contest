/* 
 * ��������a,b����[a, b)���ж�������
 * b���ڵ���С������һ������������b������a~����b��������Χ��
 * �Ϳɸ���ɸ����a~b��ɸѡ
 */
#include <cstdio>
#include <algorithm>
#define MAX_L 1000000
#define MAX_SQRT_B 1000000 // ��B������
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
        if(is_prime_small[i]) { // ��סi��ֵ����һ������
            for(int j = 2 * i; (ll)j * j < b; j += i) is_prime_small[j] = false;
            for(ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) { // ����(a+i-1)/i��Ϊ�˱�֤��a�������ʼɸ��[���������һ��j=a+1]
                is_prime[j - a] = false; // ����ָ��a��ʼ��j�����Ƿ�����
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