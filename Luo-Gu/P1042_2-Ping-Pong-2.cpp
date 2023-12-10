/* 
 * �������������������ַ�����ʾ˭Ӯ������21��11�����µ�ÿ�ֱȷ֣��ֲ����2���У�
 * 
 * ����˼·����ظĳɶ����ٴ����ͺܹ淶
 */
#include <iostream>
#include <algorithm>
#define MAX_N 62521
using namespace std;

char a[MAX_N];
int length;

void solve(int n)
{   int score[2] = {0, 0};
    for(int i = 0; i < length; i++) {
        if(a[i] == 'W') score[0]++;
        else score[1]++;
        if(max(score[0], score[1]) >= n && abs(score[0] - score[1]) >= 2) {
            cout<<score[0]<<":"<<score[1]<<endl;
            score[0] = score[1] = 0;
        }
    }
    cout<<score[0]<<":"<<score[1]<<endl;
    cout<<endl;
}

int main()
{
    length = 0;
    while(1) {
        char c = getchar();
        if(c == 'E') break;
        if(c == '\n' || c == '\r') continue;
        else a[length++] = c;
    }
    solve(11);
    solve(21);
    return 0;
}