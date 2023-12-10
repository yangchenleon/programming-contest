/* 
 * ������������Ŀ�ʼ�ͽ���ʱ�䣬���������ɼ�������
 * 
 * ̰�Ĳ�����ѡ���������������ֱ�۽����ǽ���Խ���ѡ������Խ��
 * ��������û����ȫ������֤��
 * 
 * ���ɣ�sort��Ĭ�ϲ��յ�һ���ؼ����������У�����дcmp����ȡʱ�Ͱѽ���ʱ�������һ���ؼ��֣�
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int N;
pair<int, int> work[MAX_N];

void solve()
{
    int ans = 0, t = 0; // ��¼��ǰ����ʱ��
    sort(work, work + N);

    for(int i = 0; i < N; i++) {
        if(work[i].second > t) {
            ans++;
            t = work[i].first;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &work[i].second, &work[i].first);
    }
    solve();
    return 0;
}

/* 
input
5
1 3
2 5
4 7
6 9
8 10
*/