/* 
 * 问题描述：大模拟，对一组自定义的循环语句，判定是否有语法错误，以及判定是否符合对应的时间的复杂度。具体详见题目
 * 
 * 这里有新发现，对于string变量，如果是cin>>他会读取跳过所有空格的字符串，
 * 如果是getline，则是读取光标位置直到换行的整个字符构成的字符串（包括空格但不包括换行符，吞掉换行但不处理）
 * 因此如果cin读完，位置处于换行前，再getline是读取到空串（输出的话就啥没有）而不是下一行字符串，因此要处理掉这个换行
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