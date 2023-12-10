# define MAX_N_CBJ 500000
/* 查并集(Union Find)的实现 */

int par[MAX_N_CBJ];
int rak[MAX_N_CBJ];

/* 初始化n个元素 */
void init(int n)
{
    for(int i = 0; i < n; i++) {
        par[i] = i;
        rak[i] = 0;
    }
}

/* 查询树的根 */
int find(int x)
{
    if(par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]); // 查询了的同时采用了路径压缩
    }
}

/* 合并x和y所属的集合 */
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rak[x] < rak[y]) {
        par[x] = y; // 但凡差距为1，作为子树插入也不会影响合并树的高度
    } else {
        par[y] = x;
        if(rak[x] == rak[y]) rak[x]++;
    }
}

/* 判断x和y是否属于同一集合 */
bool same(int x, int y)
{
    return find(x) == find(y);
}