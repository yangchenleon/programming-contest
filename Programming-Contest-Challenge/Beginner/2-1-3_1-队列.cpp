/* 
 * ����Ҳ��STL���ֳɵģ���ͷ�ļ�queue
 * ����push��pop��������
 * ͨ��front��ȡ����Ԫ��
 */
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    queue<int> que;
    que.push(3);
    que.push(2);
    que.push(1);
    while(que.size() > 0) {
        printf("%d\n", que.front()); 
        que.pop();
    }
    return 0;
}