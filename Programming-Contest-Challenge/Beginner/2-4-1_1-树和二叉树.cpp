/* 
 * 父节点、儿子节点、兄弟节点、叶子节点
 * 二叉树：所有节点的儿子个数都不超过2的树 
 * 
 * 下面是使用set和map的例子
 * set是不重复集合，插入两个相同的则算一个
 * 
 * 由于都是由数构成的，不能简单int i遍历，需要一个迭代器iter才行
 */
#include <cstdio>
#include <set>
#include <map>
#include <string>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(5);
    set<int>::iterator ite;
    ite = s.find(1);
    if(ite == s.end()) printf("not found\n");
    else printf("found\n");
    ite = s.find(2);
    if(ite == s.end()) printf("not found\n");
    else printf("found\n");
    s.erase(3); // 删除元素
    if(s.count(3) != 0) printf("not found\n"); // 其他查找元素的方法
    else printf("found\n");
    for(ite = s.begin(); ite != s.end(); ++ite) { // 遍历集合
        printf("%d\n", *ite);
    }

    map<int, const char*> m; // 声明了int为键，char*为值
    m.insert(make_pair(1, "ONE"));
    m.insert(make_pair(10, "TEN"));
    m[100] = "HUNDRED"; // 插入的其他写法
    map<int, const char*>::iterator iter;
    iter = m.find(1);
    printf("%s\n", iter->second);
    iter = m.find(2);
    if(iter == m.end()) printf("not found\n");
    else printf("%s\n", iter->second);
    printf("%s\n", m[10]);
    printf("%s\n", m[8]);
    m.erase(10);
    for(iter = m.begin(); iter != m.end(); ++iter) {
        printf("%d: %s\n", iter->first, iter->second);
    }

    return 0;
}