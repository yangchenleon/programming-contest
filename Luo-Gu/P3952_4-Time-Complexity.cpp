/* 
 * ������������ģ�⣬��һ���Զ����ѭ����䣬�ж��Ƿ����﷨�����Լ��ж��Ƿ���϶�Ӧ��ʱ��ĸ��Ӷȡ����������Ŀ
 * 
 * �������·��֣�����string�����������cin>>�����ȡ�������пո���ַ�����
 * �����getline�����Ƕ�ȡ���λ��ֱ�����е������ַ����ɵ��ַ����������ո񵫲��������з����̵����е�������
 * ������cin���꣬λ�ô��ڻ���ǰ����getline�Ƕ�ȡ���մ�������Ļ���ɶû�У���������һ���ַ��������Ҫ������������
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#define MAX_L 105
using namespace std;

int t, L;
string o;
struct {
    char type;
    string i, x, y;
} code[MAX_L];

void solve()
{
    bool flag = false;
    bool check1 = false, check2 = false;
    int depth = 0, cplxt = 0;
    int w = 0, tdepth;
    string sta[25];
    if(o[2] == '1') w = 0;
    else {
        int i = 0;
        while(o[4+i] != ')') i++;
        while(i) w = w * 10 + o[4+(--i)] - 48;
    } 

    for(int i = 0; i < L; i++) {
        if(flag && depth == tdepth) flag = false;
        if(code[i].type == 'F') {
            for(int j = 0; j < depth; j++) {
                if(sta[j] == code[i].i) {cout<<"ERR"<<endl; return;}
            }
            if(code[i].x == "n" && code[i].y != "n") {flag = true; tdepth = depth;}
            if(code[i].x != "n" && code[i].y == "n" && !flag) cplxt++;
            if(code[i].x != "n" && code[i].y != "n") {
                if(code[i].x.length() > code[i].y.length()) {flag = true; tdepth = depth;}
                if(code[i].x.length() == code[i].y.length() && code[i].x > code[i].y) {flag = true; tdepth = depth;}
            }
            sta[depth++] = code[i].i;
        }
        if(code[i].type == 'E') {
            depth--;
            if(depth == 0 && i < L - 1) cplxt = 0;
            if(depth < 0) break;
        }
        if(cplxt == w) check2 = true;
    }
    if(depth == 0) check1 = true;
    if(check1 && check2) cout<<"Yes"<<endl;
    else if(!check1) cout<<"ERR"<<endl;
    else cout<<"No"<<endl;
}

int main()
{
    cin>>t;
    while(t--) {
        cin>>L>>o;
        for(int i = 0; i < L; i++) {
            cin>>code[i].type;
            if(code[i].type == 'F') cin>>code[i].i>>code[i].x>>code[i].y;
        }
        solve();
    }
    return 0;
}