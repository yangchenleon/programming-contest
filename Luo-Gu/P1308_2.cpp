#include <bits/stdc++.h>
#define MAX_N 1000;
using namespace std;


int main()
{
    string sent, word;
    int lens, lenw, cnt=0, pos;

    getline(cin, word);
    getline(cin, sent); //字符串含有空格输入，不可以用cin，否则to me只能读到to
    lenw = word.size();
    lens = sent.size();
    
    //转成大写
    for (int i = 0; i < lenw; i++) word[i] = toupper(word[i]); 
    for (int i = 0; i < lens; i++) sent[i] = toupper(sent[i]);

    for (int i = 0; i <= lens - lenw; i++)
    {
        int j;
        for (j = 0; j < lenw; ++j) //逐个比较单词字母
        {
            if (sent[i + j] != word[j]) break; //单词内容不匹配
            if (i > 0 && sent[i - 1] != ' ') break; //不是单词开头就结束（去除ato me这种）
        }
        if (j == lenw && (sent[j + i] == ' ' || j + i == lens)) //单词长度匹配，后面是空格或者句末
        {
            cnt++;
            if (cnt == 1) pos = i;
        }
    }
    if (cnt == 0)
        cout << -1;
    else
        cout << cnt << " " << pos;
    return 0;
}