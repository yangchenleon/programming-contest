/* 
 * ��1��5��10��50��100��500��ֵ��Ӳ�Ҷ�ö��Ҫ����Ӳ��֧��AԪ��������Ҫ����Ӳ�ң����ٴ���һ��֧��������
 * 
 * ����ֱ�������ȸ�������������˾���С���ֱ��֧������
 * 
 * ���ɣ����ڳ������籾��������const����
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};
long long C[6], A;

void solve()
{
    int ans;
    for(int i = 5; i >= 0; i--) {
        int t = min(C[i], A / V[i]);
        ans += t;
        A -= t * V[i];
    }
    printf("%d\n", ans);
}

int main()
{
    for(int i = 0; i < 6; i++) {
        scanf("%d", &C[i]);
    }
    scanf("%d", &A);
    solve();
    return 0;
}

/*
input 
3 2 1 3 0 2
620
*/