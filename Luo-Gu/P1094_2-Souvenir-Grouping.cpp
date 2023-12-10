/* 
 * ��Ŀ��������������������Լ�������Ʒ���������������䣬����С��������
 *
 * ����˼·��̰�ľ��У���Ȼ����֤���������������е��鷳����Ҫ���Ǳ߽�����������
 * ���ѭ���У�lr�ֱ��ʾ�߽���ж�����Ʒ�������䵽ͬһ����Ʒ�������ǡ��ƥ�䣬��˿��غ�
 * �ڲ�ѭ���У�������������Ƿ��ܺ�l�ϲ���ֱ�������˺�˵��r��lƥ�䣬Ȼ��l++��r--��ʾ����һ��l���ԣ�ͬʱƥ����res++
 */
#include <iostream>
#include <algorithm>
#define MAX_N 30005
using namespace std;

int w, n;
int a[MAX_N];

void solve()
{
    int res = 0;
    int l = 0, r = n - 1;
    while(l <= r) {
        while(l < r && a[l] + a[r] > w) { res++; r--;}
        l++; r--; res++;
    }
    cout<<res<<endl;
}

int main()
{
    cin>>w>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);
    solve();
    return 0;
}

/*
input
100 
5
90
90
90
90
90
*/