/* ������������ʵ�� */
struct node {
    int val;
    node *lch, *rch;
};

/* ������ֵ */
node *insert_bst(node *p, int x)
{
    if(p == NULL) {
        node *q = new node;
        q->val = x;
        q->lch = q->rch = NULL;
        return q;
    } else {
        if(x < p->val) p->lch = insert(p->lch, x);
        else p->rch = insert(p->rch, x);
        return p;
    }
}

/* ��ѯ��ֵ */
bool find_bst(node *p, int x)
{
    if(p == NULL) return false;
    else if(x < p->val) return find(p->lch, x);
    else return find(p->rch, x);
}

/* ɾ����ֵ�����ص����õĶ����� */
node *remove_bst(node *p, int x)
{
    if(p ==  NULL) return NULL;
    else if(x < p->val) p->lch = remove(p->lch, x);
    else if(x > p->val) p->rch = remove(p->rch, x);
    else {
        if(p->lch == NULL) {
            node *q = p->rch;
            delete p;
            return q;
        } else if(p->lch->rch == NULL) {
            node *q = p->lch;
            q->rch = p->rch; // ɾ���ڵ�����������ܲ���
            delete p;
            return q;
        } else {
            node *q;
            for(q = p->lch; q->rch->rch != NULL; q = q->rch);
            node *r = q->rch;
            q->rch = r->lch; // �游�Ӿ��Ľڵ���Ȼû���Һ��ӣ��������Ӳ��ܲ���
            r->lch = p->lch;
            r->rch = p->rch;
            delete p;
            return r;
        }
    }
}
