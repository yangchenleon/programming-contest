#include <iostream>
using namespace std;
void out(int*a)
{
    for(int i=0;i<26;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    //n张牌选出m个，求是否能和m个字符串一对一匹配
    //概率就是 匹配成功种类/Cnm 要求约分
    //ofstream outfile;
    //outfile.open("21.txt");
    int T; //处理数据次数
    int n, m;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        scanf("%d %d", &n, &m);
        char card[n][3];
        char patten[m][2];
        int num_1[10] = {0};
        int cha_1[26] = {0};
        int num_2[10] = {0};
        int cha_2[26]={0};
        int i;
        for (i= 0; i < n; i++)
        {
            
            //printf("sabi:%d\n",cha_2[0]);
            scanf("%s", &card[i]);
            //out(cha_2);
            num_1[(int)(card[i][0])-'0']++;
            cha_1[(int)(card[i][1]) - 'A']+=1;
        }
        /**/
        //cout<<"heyhey"<<cha_2[0]<<endl;
        for (int i = 0; i < m; i++)
        {
            scanf("%s", patten + i);
            if ((int)(patten[i][0]) != '?')
                num_2[(int)(patten[i][0])-'0']++;
                //cout<<cha_3[0]<<endl;
            if ((int)(patten[i][1]) != '?')
            {   
                //cout<< (int)(patten[i][1]) - 65<<"FDFS"<<endl;
                cha_2[(int)(patten[i][1]) - 'A']++;
                //cout << "cha2:" <<i<<"and" <<cha_2[0] <<endl;
            }
        }

        if (m == n)
        {
            int flag = 1;
            for (int j = 0; j < 10; j++)
                if (num_2[j] > num_1[j])
                {
                    //cout << "222:" << j << endl;
                    flag = 0;
                }
            for (int j = 0; j < 26; j++)
                if (cha_2[j] > cha_1[j])
                {
                    cout << "111:" << cha_2[j] << " " << cha_1[j] << " " << j << endl;
                    flag = 0;
                }
            cout << flag << "/1" << endl;
            //outfile << flag << "/1" << endl;
            //outfile.close();
        }
        //if(m==1)
        
    }
}

/*
10
13 13
4S 4S 4S 6S 4S 4S 4S 4S 4S 6S 6S 7S 4S
?? ?S ?? ?S 4S 7S 7S 6S ?? ?? 4S ?S ??
18 18
5C 5C 9C 5C 5C 5C 9Q 5C 9C 5C 5C 5C 5C 5C 5C 5C 5C 9C
?? 5C ?C ?C ?C 5C ?? 5C ?? ?? 9C ?? 5C 9C ?C ?C ?? ??
34 34
8U 8U 7N 5N 3X 7H 7H 5N 8K 7H 7H 8K 6H 8U 4V 8K 5N 8U 8K 8U 7N 8U 8U 8K 8U 8K 8U 8U 7H 8U 5N 1K 8K 8U
8U 7H ?? ?? ?? ?U 8K 8U 7H 8U ?? ?? 8U ?? ?K ?? 8K ?? ?U ?? 5N ?K ?? ?? 6H ?? ?U ?? ?H 7H ?? ?? 8K ?N
6 6
0L 0L 0L 0L 7L 0L
?? ?? ?? ?? ?? ??
58 58
7G 7G 7G 7G 0Q 7G 3Q 3Q 0Q 7G 7G 7G 0Q 7G 0Q 0Q 0Q 0Q 0Q 0Q 0Q 7G 7G 7G 7G 0Q 7G 7G 7G 0Q 5G 0Q 0Q 7G 0Q 7G 7G 7G 7G 0Q 3Q 7G 7G 7G 7G 5Q 0Q 7G 7G 7G 1G 7G 7G 0Q 7G 7G 7G 7H
0Q 7G ?? ?? 7G ?G ?G ?Q 7G ?G ?Q 7G 7G ?? 3M ?? 0Q ?? ?? 0Q ?G ?G ?? ?? 0Q 0Q ?? 0Q 7G 7G ?? ?? 7G 7G 0Q ?? ?? 7G ?Q 7G ?G ?? ?? ?? ?? 7G ?? 4T ?? 7H ?Q ?? ?? 0Q ?G 7G 0Q ??
4 4
9Q 9Q 9Q 9Q
?? 9Q ?? ??
53 53
7I 7V 7V 7V 7V 9U 7V 7I 7I 9V 0U 7V 7V 6V 7V 7V 0V 0V 8V 7V 7I 8V 7V 8V 9V 7I 7V 7V 7V 7I 7V 8V 7I 8V 8V 7V 7V 7I 7V 7I 8V 7V 6D 0U 7V 9U 7V 7V 8V 7V 2V 6M 3Y
7V 7V 8V 3B 7V 7V 9U 7V ?V ?I 7V 7V 7V 4O 8V 7V 3Y 7V ?? 7I 7V 8V 8V 8V 9V ?V 7I 7V ?V 7V 7I 7V 7V 0P 0V ?U 9V ?V 7V 7V 7V 7V 7V 6M 7I 7V 7V 7I 7V 7V 7O 0V ?I
56 56
5J 3M 0V 5J 5J 5J 5J 5N 5J 5J 5N 6T 5J 5J 5J 5J 5J 5J 3Y 4Y 5J 5J 5J 3M 5J 5J 5J 5J 2J 5J 5J 5J 6S 9J 5J 9J 5J 5J 5J 5N 9J 5J 4N 5J 0V 5J 5J 6T 5J 5J 5J 5N 9I 5J 5J 2J
?? ?? ?? ?? ?? ?? ?? ?J ?? ?? ?? ?? ?? ?? ?M ?? ?? ?N ?J ?? ?? ?? ?J ?? ?? 5J ?? ?? ?? ?? ?? ?? ?? ?? ?N ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 5J ?? ?? 5J ?? ?? ?? ?? ?J ?? ?J
46 46
9H 1M 0X 8Y 2Y 9T 2Y 5X 5P 1U 9T 7U 8P 6U 7U 1S 5X 8Y 6P 7U 7U 1R 7U 7U 5M 3H 9H 2Y 7U 5X 8P 3T 7U 8X 7U 7U 7U 7U 6U 7U 0X 0X 7U 9H 5X 7U
7U 0X 7U ?P 2Y 9H 7U 1R ?X 2Y 6P ?X 8P 7U ?T 8Y 2Y 2Y 0I ?U 9T 7U 9T 1M 0M ?H 7U 7U ?Y 0X 3H 2Y 7U 7U 0G 0X ?X 7U ?P 8P 7U 4J 1S ?P 2Y 2Y
21 21
7E 5I 1E 7E 1E 7E 5I 5I 7E 5I 7E 5I 7E 7E 5I 7E 7E 4E 5I 7E 4D
?E ?? ?? 7E ?E ?? ?? ?? ?? ?E ?? ?? 7E 7E ?? 7E ?? ?? ?? ?? ??
*/