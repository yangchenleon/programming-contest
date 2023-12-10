/* 
 * 1. ���ȶ��У�������ֵ��ȡ����С����ֵ��ɾ��
 * STL����prioroty_queue�������ȶ��У�������ȡ�����ֵ�������ж�ʵ��
 * 
 * 2. �ѣ����ӵ�ֵһ����С�ڸ��׵�ֵ��
 * ����=����������ĩβ���벻��������+ȡ����Сֵ��������βԪ�ز������������Ӷȶ���nlogn��
 * ��HEAP.h����ʵ��
 * 
 * ����������������P��λ�ͣ���ʻL���ÿ��������һ��λ�ͣ�
 * ·��n������վ��ÿ���������A���룬�ṩ���B���ͣ����ܷ�ִ��յ�
 * 
 * ���Լ�д�ģ����ĵ�ǰ�ͺ���ͣ��Ƿ��ܵ���Ŀ�ĵ�
 * 
 * �ٷ��汾���Ƿ��ܾ���ÿһ������վ
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX_N 10000
#define MAX_L 1000000
#define MAX_P 1000000
using namespace std;

int N, L, P;
int A[MAX_N+1];
int B[MAX_N+1];

void solve()
{
    priority_queue<int> que;
    
    int ans = 0, pos = 0, tank = 0;
    int i = 0;
    que.push(P);
    while(!que.empty()) {
        if(pos >= L) break;
        pos += que.top();
        que.pop();
        ans++;
        while(i <= pos) {
            que.push(B[i++]);
        }
    }
    if(pos >= L) printf("%d\n", ans - 1); // ��Ϊ�ѳ�ʼ��Ҳ�����ˣ���Ҫ��һ
    else printf("%d\n", -1);

    while(!que.empty()) que.pop(); 
    A[N] = L, B[N] = 0;
    ans = 0, pos = 0,tank = P;
    for(int i = 0; i <= N; i++) {
        int d = A[i] - pos; // ����һ������վ�ľ���
        while(tank - d < 0) {   // �����ͼӵ���
            if(que.empty()) {
                puts("-1");
                return;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d%d%d", &N, &L, &P);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &A[i], &B[i]);
    }
    solve();
    return 0;
}

/* 
input
4 25 10
10 10
14 5
20 2
21 4
*/