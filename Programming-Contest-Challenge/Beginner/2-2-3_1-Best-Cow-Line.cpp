/* 
 * һ����n���ַ�����ͷ��β��һ���ַ�����һ���ַ����飬ʹ�乹������ֵ���strcmp�ıȽϷ�����a<b��
 * 
 * ����ȡ��С�ģ����������ͬ��Ҫ�������м�Ƚ�ֱ��������С�ߣ�ʹС�˾���¶����
 */
#include <cstdio>
#define MAX_N 2010
using namespace std;

int N;
char S[MAX_N]; // ���ȡ2000��Ӧ����MAX_N+1, Ϊ\0���ռ�

void solve()
{
    int l = 0, r = N - 1;
    while(l <= r) {
        bool left = false;
        for(int i = 0; l + i <= r; i++) { // �Ҿ�������ѭ������̫���ˣ���l+i<=r-i�͹���
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