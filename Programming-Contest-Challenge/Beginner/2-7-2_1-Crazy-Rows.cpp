/* 
 * ������������һ��0/1����ֻ�������������У��󻯳������Ǿ�����Ҫ�������Σ���֤�ܻ��ɣ�
 * 
 * ����˼·������̰�ԣ�����Ŀ���λ�õ��������ƶ�����֪��Ϊɶ����ֻ���¼����ĩβ1��λ�þ��ܱ�ʾ����
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 45
using namespace std;

int n;
int a[MAX_N];

void solve()
{
    int res = 0;
    for(int i = 0; i < n; i++) { // ���������Ǿ���������Ѱ�ҷ���a[j]<=i�����һ��pos������i��
        int pos = -1;
        for(int j = i; j < n; j++) {
            if(a[j] <= i) { // ����==���еģ�Ϊʲô�أ��������3
                pos = j;
                break;
            }
        }

        for(int j = pos; j > i; j--) {
            swap(a[j], a[j-1]);
            res++;
        }
    }
    printf("%d\n", res);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char tmp[n];
        a[i] = -1; // ȫ�����
        scanf("%s", tmp); // ��������������ģ����鷳
        for(int j = 0; j < n; j++) {
            if(tmp[j] == '1') a[i] = j;
        }
    }
    solve();
    return 0;
}

/*
input1
2
10
11

input2
3
001
100
010

input3 
4
1110
1100
1100
1000
*/