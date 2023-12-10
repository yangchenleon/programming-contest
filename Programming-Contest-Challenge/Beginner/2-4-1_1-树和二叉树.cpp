/* 
 * ���ڵ㡢���ӽڵ㡢�ֵܽڵ㡢Ҷ�ӽڵ�
 * �����������нڵ�Ķ��Ӹ�����������2���� 
 * 
 * ������ʹ��set��map������
 * set�ǲ��ظ����ϣ�����������ͬ������һ��
 * 
 * ���ڶ����������ɵģ����ܼ�int i��������Ҫһ��������iter����
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
    s.erase(3); // ɾ��Ԫ��
    if(s.count(3) != 0) printf("not found\n"); // ��������Ԫ�صķ���
    else printf("found\n");
    for(ite = s.begin(); ite != s.end(); ++ite) { // ��������
        printf("%d\n", *ite);
    }

    map<int, const char*> m; // ������intΪ����char*Ϊֵ
    m.insert(make_pair(1, "ONE"));
    m.insert(make_pair(10, "TEN"));
    m[100] = "HUNDRED"; // ���������д��
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