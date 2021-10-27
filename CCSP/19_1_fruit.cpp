#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //苹果树1-n；梨树n+1-2n
    //i号果子：美味度ai；限制bi果摘
    //后果限制前果;不限制不同树上的果
    //每次每树一果。价值为ai按位异或，重复n次
    int n;
    cin >> n;
    int a[2 * n];
    int b[2 * n];
    int sta[2 * n] = {0};
    for (int i = 0; i < 2 * n; i++) //读取美味度
    {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    for (int i = 0; i < 2 * n; i++) //设置限制对象
    {
        int tmp;
        cin >> tmp;
        b[i] = tmp;
        sta[b[i] - 1]++;
    }
    for (int x = 0; x < n; x++) //执行n次筛选输出
    {
        int cho_ap, cho_pr;
        int max = -1;
        for (int i = 0; i < n; i++) //筛选苹果
        {
            if (sta[i] == 0) //选中没有限制的苹果
            {
                for (int j = n; j < 2 * n; j++) //筛选梨
                {
                    if (sta[j] == 0) //苹果选中且梨没有限制，下面开始选最佳情况
                    {
                        int sum = a[i] ^ a[j];
                        //printf("heshia:%d %d %d\n", i + 1, j + 1, max);
                        if (sum > max) //最优情况1，并记录序号
                        {
                            max = sum;
                            cho_ap = i;
                            cho_pr = j;
                        }
                        else if (sum == max)
                        {
                            if (a[i] > a[cho_ap]) //最优情况2
                            {
                                cho_ap = i;
                                cho_pr = j;
                            }
                            else if (a[i] == a[cho_ap])
                            {
                                if (i > cho_ap) //最优情况3
                                {
                                    cho_ap = i;
                                    cho_pr = j;
                                }
                                else if (i == cho_ap) //最优情况4
                                    cho_pr = cho_pr < j ? j : cho_pr;
                            }
                        }
                    }
                }
            }
        }
        sta[b[cho_ap] - 1]--;
        sta[b[cho_pr] - 1]--;
        sta[cho_ap] = -1;
        sta[cho_pr] = -1;
        cout << max << ' ';
    }
}