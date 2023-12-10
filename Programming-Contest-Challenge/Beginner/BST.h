/* 二叉搜索树的实现 */
struct node {
    int val;
    node *lch, *rch;
};

/* 插入数值 */
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

/* 查询数值 */
bool find_bst(node *p, int x)
{
    if(p == NULL) return false;
    else if(x < p->val) return find(p->lch, x);
    else return find(p->rch, x);
}

/* 删除数值，返回调整好的二叉树 */
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
            q->rch = p->rch; // 删除节点的右子树不能不管
            delete p;
            return q;
        } else {
            node *q;
            for(q = p->lch; q->rch->rch != NULL; q = q->rch);
            node *r = q->rch;
            q->rch = r->lch; // 替父从军的节点虽然没有右孩子，但其左孩子不能不管
            r->lch = p->lch;
            r->rch = p->rch;
            delete p;
            return r;
        }
    }
}
