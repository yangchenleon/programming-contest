# define MAX_N_HP 10000

/* �ѣ�����ѣ���ʵ�� */
int heap[MAX_N_HP], sz = 0;
void push_heap(int x)
{
    int i = sz++; // ���ĩβ�ڵ�ı��
    while(i > 0) {
        int p = (i - 1) / 2; // ���׽ڵ�ı��
        if(heap[p] <= x) break; // ����Ѿ�û�д�С�ߵ����ȥ
        heap[i] = heap[p]; // �Ѹ��׽ڵ����ֵ�������������Լ�����ȥ
        i = p;
    }
    heap[i] = x;
}

int pop_heap()
{
    
    int ret = heap[0]; // ��Сֵ
    int x = heap[sz--]; // Ҫ�ᵽ����ֵ��--��ɾ����ĩβ�ڵ�
    int i = 0; // �Ӹ���ʼ���½���
    while(i * 2 + 1 < sz) {
        int a = i * 2 + 1, b = i * 2 + 2; // �Ƚ϶��ӵ�ֵ
        if(b < sz && heap[b] < heap[a]) a = b; // ����Ѿ�û�д�С�ߵ����ˣ�ѡ�������н�С��
        if(heap[a] >= x) break; // �Ѷ��ӵ���ֵ������
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}