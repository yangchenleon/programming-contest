/* 
 * ���������һ�鳤ΪN��ľ��Ҫ���N�ݣ���֪�����N�ݵĸ�������
 * ��һ�εĿ���������ľ�峤�ȵĺͣ�����С����
 * 
 * �⣺����ת��ΪҶ�ӽڵ��������ܺ;����ܿ��� 
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 20000
using namespace std;

typedef long long ll;

int N;
int L[MAX_N];

void solve() 
{
    ll ans = 0;
    while(N > 1) {
        int mii1 = 0, mii2 = 1;
        if(L[mii1] > L[mii2]) swap(mii1, mii2);

        for(int i = 2; i < N; i++) {
            if(L[mii1] > L[i]) {
                mii2 = mii1;
                mii1 = i;
            } else if(L[mii2] > L[i]) {
                mii2 = i;
            }
        }

        int t = L[mii1] + L[mii2];
        ans += t;
        if(mii1 == N - 1) swap(mii1, mii2);
        L[mii1] = t;
        L[mii2] = L[N-1];
        N--;
    }
    printf("%lld\n", ans);
}
int main() 
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }
    solve();
    return 0;
}

/* 
input
3
8 5 8
*/