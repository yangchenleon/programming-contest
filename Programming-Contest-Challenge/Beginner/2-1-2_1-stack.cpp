/* 
 * STL有现成的栈，在头文件stack
 * 包含pop和push两个操作
 * 通过top方法获取栈顶元素
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