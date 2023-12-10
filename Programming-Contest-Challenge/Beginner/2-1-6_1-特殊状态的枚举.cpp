/* 
 * ��ö�����п��ܵ�״̬������ɸѡ�����
 * STL�ṩ�ֳɵĺ�����next_permutation���԰�n��Ԫ�ع�n!�ֲ�ͬ�������ɳ����������ֵ�˳�����ɣ�
 * Ҳ�����Լ�д��perm1����
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 100
using namespace std;

bool used[MAX_N];
int perm[MAX_N];

void permutation1(int pos, int n)
{
    if(pos == n) { // ˵�������յ㣬���һ������
        /* 
         * ��д��Ҫ��perm���еĲ���
         * ����������������
         */
        for(int i = 0; i < n; i++) {
            printf("%d", perm[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i++) { // ��posλ�ã���������û�б��õ�������perm
        if(!used[i]) {
            perm[pos] = i;
            used[i] = true;
            permutation1(pos + 1, n);
            used[i] = false;
        }
    }
    return;
}

void permutation2(int n)
{
    for(int i = 0; i < n; i++) { // �˴��൱�ڸ���������Ҫ�������е�Ԫ�ؼ���
        perm[i] = i;
    }
    do {
        /* 
         * ��д��Ҫ��perm���еĲ���
         * ����������������
         */
        printf("\t");
        for(int i = 0; i < n; i++) {
            printf("%d", perm[i]);
        }
        printf("\n");
    } while(next_permutation(perm, perm + n)); // �����������ɺ󷵻�false
    return;
}

int main()
{
    permutation1(0, 4);
    permutation2(4);
    return 0;
}