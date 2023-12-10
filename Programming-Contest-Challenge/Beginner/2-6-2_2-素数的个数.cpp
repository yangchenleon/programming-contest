/* 
 * ��ʽɸ��������������������Բ��ԣ���������Χ����������
 * 
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 1000000
using namespace std;

int n;
int prime[MAX_N]; // �洢����
bool is_prime[MAX_N];

int sieve(int n)
{
    int p = 0; // ��p������
    fill(is_prime, is_prime + n, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 0; i <= n; i++) {
        if(is_prime[i]) {
            prime[p++] = i;
            for(int j = 2 * i; j <= n; j += i) is_prime[j] = false; // �����ı���һ����������
            //for(int j = 2; i * j <= n; j++) is_prime[i * j] = false; // �о������ֱ��
        }
    }
    return p; // ���ڴ�0��ʼ�������p���������ĸ���
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