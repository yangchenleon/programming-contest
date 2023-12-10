/* 
 * �������������������ַ�����ʾ˭Ӯ������21��11�����µ�ÿ�ֱȷ֣��ֲ����2���У�
 * 
 * ������̣�����Ϊ�߶��ߴ���ע�����һ���Ǹոպ�һ�ֽ�����Ҫ���0��0��
 * 
 * ���ڽ�������Һþõ����⣬Ϊʲô֮ǰ�ñ߶���д�Ͳ��У���ʵ���ⲻ���⣬
 * ����������ͱ��ز�һ������������ǻس�������ֻ�����˻��У������һ��ȡ���س����������´���
 * ��֮����ֱ���ж���W����L��������else���Ŀ죬�����Ϊֱ���ж�WL����һ�ݸ�Ϊ�����лس�
 */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, int>> game1, game2;

void solve()
{
    int scoreW1 = 0, scoreL1 = 0;
    int scoreW2 = 0, scoreL2 = 0;
    char c;
    while((c=getchar())!='E') {
        if(c == 'W') {scoreW1++; scoreW2++;}
        if(c == 'L') {scoreL1++; scoreL2++;}
        if(max(scoreW1, scoreL1) >= 11 && abs(scoreW1 - scoreL1) >= 2) {
            game1.push(make_pair(scoreW1, scoreL1));
            scoreW1 = scoreL1 = 0;
        }
        if(max(scoreW2, scoreL2) >= 21 && abs(scoreW2 - scoreL2) >= 2) {
            game2.push(make_pair(scoreW2, scoreL2));
            scoreW2 = scoreL2 = 0;
        }
    }
    game1.push(make_pair(scoreW1, scoreL1));
    game2.push(make_pair(scoreW2, scoreL2));
    while(!game1.empty()) {
        pair<int, int> game = game1.front(); game1.pop();
        cout<<game.first<<":"<<game.second<<endl;
    }
    cout<<endl;
    while(!game2.empty()) {
        pair<int, int> game = game2.front(); game2.pop();
        cout<<game.first<<":"<<game.second<<endl;
    }
    cout<<endl;
}

int main()
{
    solve();
    return 0;
}