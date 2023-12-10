/* 
 * �����������б��1-N���ﷸ��Ҫ�ͷ�һ���ﷸ�������Ҳ�ֱ���շ���������ﷸ��Ҫ��һöӲ�ң�
 * ��Ҫ�ͷ�ĳЩ������ﷸ����������Ҫ����Ӳ��
 * 
 * ����˼·��permutationö�����п��ܣ�����״̬���飬��¼���Ƿ�Ϊ��, ����Ҳ������ֱ���ո�, ����ǰ���ֵΪ��
 * ����Ȼ̫�����ˣ���dp[i][j]��ʾA[i],A[j]֮�䣨��������ͷ�������������������ﷸ���ͷŵ���С���������
 * Ȼ�����൱�ڶ������ֽ������̣��Ե����Ϸ�����һ��ʼ�������ں�0������������Q�����ͷ���������������w�����ʾ
 * ��������ѡ��������С�ļ��ɣ�����������ˣ��������Ǻ��±ư�
 */
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAX_N 10000
#define MAX_Q 100
using namespace std;

int P, Q;
int A[MAX_Q+2]; // �ͷ��ﷸ�ı�ţ��±��1��ʼ

bool used[MAX_Q];
int perm[MAX_Q];
int ans = INF;
void permutation(int pos, int n)
{
    if(pos == n) {
        bool empty[P+1];
        fill(empty, empty + P + 1, false);
        int res = 0;
        empty[P+1] = empty[0] = true;
        for(int i = 0; i < n; i++) {
            int j = perm[i];
            while(!empty[++j]) res++;
            j = perm[i];
            while(!empty[--j]) res++;
            empty[perm[i]] = true;
        }
        ans = min(ans, res);
    }
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            used[i] = true;
            perm[pos] = A[i+1];
            permutation(pos + 1, n);
            used[i] = false;
        }
    }
    return;
}

int dp[MAX_Q+1][MAX_Q+2];
void solve()
{
    A[0] = 0; A[Q+1] = P + 1; // ���㴦����˵���0�ŷ����Ҷ�Q+1�ŷ�������dp[0][Q+1]���Ǵ�
    for(int q = 0; q < Q; q++) dp[q][q+1] = 0;
    for(int w = 2; w <= Q + 1; w++) { // ���䳤�ȣ����������Σ�Q���㣬����г�Q+1��
        for(int i = 0; i + w <= Q + 1; i++) {
            int j = i + w, t = INF;
            for(int k = i + 1; k < j; k++) {
                t = min(t, dp[i][k] + dp[k][j]);
            }
            dp[i][j] = t + A[j] - A[i] - 2; // �ͷ��ﷸ���¸��������ˣ�Ȼ��ȥ����ͷ
        } 
    }
    printf("%d\n", dp[0][Q+1]);
}

int main()
{
    scanf("%d%d", &P, &Q);
    for(int i = 0; i < Q; i++) {
        scanf("%d", &A[i+1]);
    }
    permutation(0, Q);
    printf("%d\n", ans);
    return 0;
}

/*
input1
8 1
3

input2
20 3
3 6 14
*/