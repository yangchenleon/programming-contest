/* 
 * STL���ֳɵ�ջ����ͷ�ļ�stack
 * ����pop��push��������
 * ͨ��top������ȡջ��Ԫ��
 */
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(s.size() > 0) {
        printf("%d\n", s.top());
        s.pop();
    }
    return 0;
}