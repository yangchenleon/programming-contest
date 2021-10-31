#include <iostream>
#include <algorithm>
#include <string>
#include <string>
using namespace std;
bool isspace(string &s)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            return false;
    return true;
}

int main()
{
    //空行代表 段落，表现为读行为一个\n
    //连续的空（回车+多余空格）记为一个空格
    //若一个段落的新一行空格打头，去掉
    //getline中，回车不计数
    int w;
    cin >> w;
    string line;
    while (getline(cin, line))
    {
        if(!isspace(line))
        {
            cout<<line.length();
            //说明可以新的一段，行数+1
        }
        //else //还在段中，继续输出
        //{
            //输出要根据w换行，需要计数
            //当首个为空时忽略
            //改行非空 需处理多个空格情况。
        //}
        cout << line.length();
    }
}