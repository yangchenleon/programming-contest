/* 
 * 问题描述：给定若干字符串表示谁赢，求在21和11赛制下的每局比分（分差大于2才行）
 * 
 * 解题过程：设置为边读边处理，注意最后一轮是刚刚好一局结束，要输出0：0的
 * 
 * 终于解决卡了我好久的问题，为什么之前用边读边写就不行，其实问题不在这，
 * 好像评测机和本地不一样，他上面的是回车，我这只处理了换行，导致我会读取到回车，进而导致错误
 * 总之不如直接判定是W还是L，而不用else来的快，这里改为直接判定WL，另一份改为处理换行回车
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