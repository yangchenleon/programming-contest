# define MAX_N_CBJ 500000
/* �鲢��(Union Find)��ʵ�� */

int par[MAX_N_CBJ];
int rak[MAX_N_CBJ];

/* ��ʼ��n��Ԫ�� */
void init(int n)
{
    for(int i = 0; i < n; i++) {
        par[i] = i;
        rak[i] = 0;
    }
}

/* ��ѯ���ĸ� */
int find(int x)
{
    if(par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]); // ��ѯ�˵�ͬʱ������·��ѹ��
    }
}

/* �ϲ�x��y�����ļ��� */
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rak[x] < rak[y]) {
        par[x] = y; // �������Ϊ1����Ϊ��������Ҳ����Ӱ��ϲ����ĸ߶�
    } else {
        par[y] = x;
        if(rak[x] == rak[y]) rak[x]++;
    }
}

/* �ж�x��y�Ƿ�����ͬһ���� */
bool same(int x, int y)
{
    return find(x) == find(y);
}