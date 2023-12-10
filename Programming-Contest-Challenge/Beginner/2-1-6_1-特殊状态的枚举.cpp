/* 
 * 及枚举所有可能的状态，从中筛选出最佳
 * STL提供现成的函数：next_permutation可以把n个元素共n!种不同排列生成出来（按照字典顺序生成）
 * 也可以自己写，perm1就是
 */
#include <cstdio>
#include <algorithm>
#define MAX_N 100
using namespace std;

bool used[MAX_N];
int perm[MAX_N];

void permutation1(int pos, int n)
{
    if(pos == n) { // 说明到达终点，完成一种排列
        /* 
         * 编写需要对perm进行的操作
         * 如接下来的输出排列
         */
        for(int i = 0; i < n; i++) {
            printf("%d", perm[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i++) { // 对pos位置，尝试所有没有被用的数填入perm
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
    for(int i = 0; i < n; i++) { // 此处相当于给出所有需要构成排列的元素集合
        perm[i] = i;
    }
    do {
        /* 
         * 编写需要对perm进行的操作
         * 如接下来的输出排列
         */
        printf("\t");
        for(int i = 0; i < n; i++) {
            printf("%d", perm[i]);
        }
        printf("\n");
    } while(next_permutation(perm, perm + n)); // 所有排列生成后返回false
    return;
}

int main()
{
    permutation1(0, 4);
    permutation2(4);
    return 0;
}