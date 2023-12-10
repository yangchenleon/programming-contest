/* 
 * ���鼯:���ڹ�����飬ִ�в�ѯ�Ƿ�ͬһ�顢�ϲ����������޷����
 * �����˻����ڵ��ٵ����ߣ�����ȡС�߽Ӵ�ߡ�·��ѹ����ֱ������������������������
 * �����ľ�̯���Ӷ���a(n)����logn��Ҫ��
 * 
 * ���������N��������1-N��������ABC����һ�֣���֪A��B��B��C��C��A��
 * �������K����¼����¼�����֣�x��y����ͬһ�֡�x��y
 * ǰ�������ì�ܣ�֮���������
 * 
 * ���⣺����3N������N������ֱ�����ABC���¼���
 * ͬһ���ڵ��¼�Ҫôͬʱ������Ҫôͬʱ������
 * ����type1���жϣ����x-A y-C ��������˵��C��A��������
 * ��ʱ��Ȼx-B y-A��x-C y-B��ͬһ�飬������Щ����ͬ�����ж�
 * ����type2���жϣ����x-A y-A��ͬһ�飬��ôx-B y-BҲ��һ��
 * ��֮�������x-A����º�y��A��C��ͬһ�飬��ôx-B�����Ҳ�������y-C��Aһ��
 * ��Ȼ��AC�����У����鼯�Ĵ�С�������õ�̫С��
 */
#include <cstdio>
#include "UFSet.h"
#define MAX_N 50000
#define MAX_K 100000
using namespace std;

int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];

void solve()
{
    init(N * 3); // ��ʼ�����鼯��ÿN���ֱ����x-A��x-B��x-C����˼����i+0����A�࣬+N����B�࣬+2N����C��
    
    int ans = 0;
    for(int i = 0; i < K; i++) {
        int t = T[i];
        int x = X[i] - 1, y = Y[i] - 1; // ���鼯�Ǵ�0��ʼ�ģ���ת��
        if(x < 0 || N <= x || y < 0 || N <= y) {
            ans++; // ��������Խ����󣬲�ֱ���������������ж�
            continue;
        }
        if(t == 1) {
            if(same(x, y + N) || same(x, y + 2 * N)) { 
                ans++;
            } else {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }
        }
        if(t == 2) {
            if(same(x, y) || same(x, y + 2 * N)) {
                ans++;
            } else {
                unite(x, y + N);
                unite(x + N, y + 2 * N);
                unite(x + 2 * N, y);
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < K; i++) {
        scanf("%d %d %d", &T[i], &X[i], &Y[i]);
    }
    solve();
    return 0;
}

/* 
input
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
*/