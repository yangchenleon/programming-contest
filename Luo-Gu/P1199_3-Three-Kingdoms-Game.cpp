/* 
 * ��Ŀ��������n���佫��������Ĭ���ȣ��Һͻ�������ѡ�佫������ÿ���ܻ�ѡ���������ܹ������Ĭ�����佫
 * ����Һͻ�������2v2�����������Ƿ���Ӯ������Ӯ���������佫Ĭ����
 * 
 * ����˼·��̰�ģ�ÿ��ѡ�δ���佫������ÿ�������ģ���ζ����Ҳ�޷��ó�����Ĭ����
 * �Ǿ�ȡ�δ󣬼�Ȼ���޷���������Ҿ���������������Զ��Ӯ��
 * ע��������Ϊ��λȡ�δ���Ϊ�����ĳһ���佫ѡ�δ󣬼�ÿ��ѡһ��������ȫ�ִδ�
 * ȫ�ִδ������ĳ���������佫������޷�ȡ���ģ����������Ƿ�ѡ������û��Ҫ��
 */
#include <iostream>
#include <algorithm>
#define MAX_N 505
using namespace std;

int N;
long long a[MAX_N][MAX_N];

void solve()
{
    long long res = -1;
    for(int i = 0; i < N; i++) {
        long long mx1 = -1, mx2 = -1;
        for(int j = 0; j < N; j++) {
            if(a[i][j] > mx1) {
                mx2 = mx1;
                mx1 = a[i][j];
            } else if(a[i][j] > mx2) {
                mx2 = a[i][j];
            }
        }
        res = max(res, mx2);
    }
    cout<<'1'<<endl;
    cout<<res<<endl;
}

int main()
{
    cin>>N;
    long long res = 0;
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - 1 - i; j++) {
            cin>>a[i][i+1+j]; // i+1��ʾi����һ���佫��j��ʾƫ����
            a[i+1+j][i] = a[i][i+1+j];            
        }    
    }
    solve();
    return 0;
}

/* 
input
8 
42 24 10 29 27 12 58 
31 8 16 26 80 6 
25 3 36 11 5 
33 20 17 13 
15 77 9 
4 50 
19 
*/