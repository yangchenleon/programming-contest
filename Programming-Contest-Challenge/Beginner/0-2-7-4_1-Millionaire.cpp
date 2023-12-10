/* 
 * ����������һ��ʼ��XԪ���������M�ֶĲ�������P���ʽ���ס����������1000000Ԫ�ĸ���
 * 
 * ���˼·���ѵ����������ԣ���ע��һ��Ϊ������������������ɻ�����Ϊ��ɢ����֪��Ϊʲô���ԣ�
 * ���ǾͿ�����������ˣ�Ȼ��ĳɶ�̬�滮�������large
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_M 15
using namespace std;
typedef long long ll;

int M, X;
double P;
double dp[2][(1<<MAX_M)+1]; // ���鸴��

void solve()
{
    int n = 1 << M;
    double *prv = dp[0], *nxt = dp[2];
    memset(prv, 0, sizeof(double) * (n + 1));
    prv[n] = 1.0;

    for(int r = 0; r < M; r++) {
        for(int i = 0; i <= n; i++) {
            int jub = min(i, n - i);
            double t = 0.0;
            for(int j = 0; j <= jub; j++) {
                t = max(t, P * prv[i+j] + (1 - P) * prv[i-j]);
            }
            nxt[i] = t;
        }
        swap(prv, nxt);
    }
    int i = (ll)X * n / 1000000;
    printf("%.6f\n", prv[i]);
}

int main()
{
    scanf("%d%lf%d", &M, &P, &X); // ����һ��Ҫ��lf
    solve();
    return 0;
}

/*
input1
1 0.5 500000

input2
3 0.75 600000
*/