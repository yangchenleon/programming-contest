#include <bits/stdc++.h>
#define MAX_N 1000;
using namespace std;


int main()
{
    string sent, word;
    int lens, lenw, cnt=0, pos;

    getline(cin, word);
    getline(cin, sent); //�ַ������пո����룬��������cin������to meֻ�ܶ���to
    lenw = word.size();
    lens = sent.size();
    
    //ת�ɴ�д
    for (int i = 0; i < lenw; i++) word[i] = toupper(word[i]); 
    for (int i = 0; i < lens; i++) sent[i] = toupper(sent[i]);

    for (int i = 0; i <= lens - lenw; i++)
    {
        int j;
        for (j = 0; j < lenw; ++j) //����Ƚϵ�����ĸ
        {
            if (sent[i + j] != word[j]) break; //�������ݲ�ƥ��
            if (i > 0 && sent[i - 1] != ' ') break; //���ǵ��ʿ�ͷ�ͽ�����ȥ��ato me���֣�
        }
        if (j == lenw && (sent[j + i] == ' ' || j + i == lens)) //���ʳ���ƥ�䣬�����ǿո���߾�ĩ
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