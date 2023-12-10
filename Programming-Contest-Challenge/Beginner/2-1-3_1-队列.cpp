/* 
 * 队列也在STL有现成的，在头文件queue
 * 包含push和pop基本操作
 * 通过front获取队首元素
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