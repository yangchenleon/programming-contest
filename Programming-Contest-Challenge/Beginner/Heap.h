# define MAX_N_HP 10000

/* 堆（大根堆）的实现 */
int heap[MAX_N_HP], sz = 0;
void push_heap(int x)
{
    int i = sz++; // 存放末尾节点的编号
    while(i > 0) {
        int p = (i - 1) / 2; // 父亲节点的编号
        if(heap[p] <= x) break; // 如果已经没有大小颠倒则出去
        heap[i] = heap[p]; // 把父亲节点的数值放下来，而把自己提上去
        i = p;
    }
    heap[i] = x;
}

int pop_heap()
{
    
    int ret = heap[0]; // 最小值
    int x = heap[sz--]; // 要提到根的值，--即删除了末尾节点
    int i = 0; // 从根开始向下交换
    while(i * 2 + 1 < sz) {
        int a = i * 2 + 1, b = i * 2 + 2; // 比较儿子的值
        if(b < sz && heap[b] < heap[a]) a = b; // 如果已经没有大小颠倒则倒退，选出儿子中较小的
        if(heap[a] >= x) break; // 把儿子的数值提上来
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}