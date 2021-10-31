#include <iostream>
#include <queue>
using namespace std;
enum Etype
{
    IN,
    NOT,
    AND,
    OR,
    XOR,
    NAND,
    NOR
};                     //枚举元件类型，IN为输入
const int Nmax = 3005; //设置包括输入点的最大元件数量
int d[1000];           //拓扑排序时记录结点的前置结点数（入度）
int inp[3000][10000];  //记录输入
//定义元件结构体
typedef struct
{
    Etype tp;     //元件类型
    int val;      //元件输出值，未被搜索到时记为-1
    int innum;    //该元件的输入个数
    int input[6]; //该元件的输入源
    /*Eelem()
    {
        this->innum = 0;
        this->tp 
        = IN;
        this->val = -1;
        for (int i = 0; i < 6; i++)
        {
            this->input[i] = -1;
        }
    }*/
} Eelem;
Eelem Eroad[Nmax]; //整体电路
int output(int i);
//结点为NOT元件时求其输出；
int NOTout(int i)
{
    if (Eroad[i].val == -1)
    {
        Eroad[i].val = !output(Eroad[i].input[0]);
    }
    return Eroad[i].val;
}
//结点为AND元件时求其输出；
int ANDout(int i)
{
    int c = 1;
    if (Eroad[i].val == -1)
    {
        for (int j = 0; j < Eroad[i].innum; j++)
        {
            c = c & output(Eroad[i].input[j]);
        }
        Eroad[i].val = c;
    }
    return Eroad[i].val;
}
//结点为OR元件时求其输出；
int ORout(int i)
{
    int c = 0;
    if (Eroad[i].val == -1)
    {
        for (int j = 0; j < Eroad[i].innum; j++)
        {
            c = c | output(Eroad[i].input[j]);
        }
        Eroad[i].val = c;
    }
    return Eroad[i].val;
}
//结点为XOR元件时求其输出；
int XORout(int i)
{
    if (Eroad[i].val == -1)
    {
        int c = output(Eroad[i].input[0]);
        for (int j = 1; j < Eroad[i].innum; j++)
        {
            c = c ^ output(Eroad[i].input[j]);
        }
        Eroad[i].val = c;
    }
    return Eroad[i].val;
}
//结点为NAND元件时求其输出；
int NANDout(int i)
{
    int c = 1;
    if (Eroad[i].val == -1)
    {
        for (int j = 0; j < Eroad[i].innum; j++)
        {
            c = c & output(Eroad[i].input[j]);
        }
        Eroad[i].val = !c;
    }
    return Eroad[i].val;
}
//结点为NOR元件时求其输出；
int NORout(int i)
{
    int c = 0;
    if (Eroad[i].val == -1)
    {
        for (int j = 0; j < Eroad[i].innum; j++)
        {
            c = c | output(Eroad[i].input[j]);
        }
        Eroad[i].val = !c;
    }
    return Eroad[i].val;
}
//对标号为i的结点求其输出
int output(int i)
{
    if (Eroad[i].tp == IN)
    {
        return Eroad[i].val;
    }
    else if (Eroad[i].tp == NOT)
    {
        return NOTout(i);
    }
    else if (Eroad[i].tp == AND)
    {
        return ANDout(i);
    }
    else if (Eroad[i].tp == OR)
    {
        return ORout(i);
    }
    else if (Eroad[i].tp == XOR)
    {
        return XORout(i);
    }
    else if (Eroad[i].tp == NAND)
    {
        return NANDout(i);
    }
    else if (Eroad[i].tp == NOR)
    {
        return NORout(i);
    }
    else
    {
        return -1;
    }
}
//设定j号元件（非输入点）的类型
int setelemtype(string s, int M, int j)
{
    if (s == "NOT")
    {
        Eroad[M + j].tp = NOT;
    }
    else if (s == "AND")
    {
        Eroad[M + j].tp = AND;
    }
    else if (s == "OR")
    {
        Eroad[M + j].tp = OR;
    }
    else if (s == "XOR")
    {
        Eroad[M + j].tp = XOR;
    }
    else if (s == "NAND")
    {
        Eroad[M + j].tp = NAND;
    }
    else if (s == "NOR")
    {
        Eroad[M + j].tp = NOR;
    }
    else
    {
        return -1;
    }
}
//使用拓扑排序算法判断是否有环存在；
bool IsCircle(int M, int N)
{
    queue<int> q;
    bool ans = false;
    for (int i = 0; i < N; i++)
    {
        if (d[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < Eroad[M + v].innum; i++)
        {
            if (Eroad[M + v].input[i] >= M)
            {
                d[Eroad[M + v].input[i] - M]--;
                if (!d[Eroad[M + v].input[i] - M])
                    q.push(Eroad[M + v].input[i] - M);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (d[i] != 0)
            ans = true;
    }
    return ans;
}
int main()
{
    int Q, M, N, k, S, front, si, ans;
    string et;
    char sym;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> M >> N;
        //设定M个输入点
        for (int j = 0; j < M; j++)
        {
            Eroad[j].tp = IN;
            Eroad[j].val = -1;
        }
        //初始化拓扑排序所用入度数组
        for (int j = 0; j < 1000; j++)
        {
            d[j] = 0;
        }
        //设置各个元件
        for (int j = 0; j < N; j++)
        {
            Eroad[M + j].val = -1;
            cin >> et;
            setelemtype(et, M, j); //设置元件类型
            cin >> k;
            Eroad[M + j].innum = k; //设置元件输入数量
            for (int c = 0; c < k; c++)
            {
                getchar();
                sym = getchar();
                cin >> front;
                if (sym == 'I')
                {
                    Eroad[M + j].input[c] = front - 1; //输入源为输入点
                }
                else
                {
                    Eroad[M + j].input[c] = front + M - 1; //输入源为其他元件
                    d[front - 1] += 1;                     //此时将输入源对应元件的入度加1
                }
            }
        }
        //读取运行次数
        cin >> S;
        //记录各次输入
        for (int j = 0; j < S; j++)
        {
            for (int c = 0; c < M; c++)
            {
                cin >> inp[c][j];
            }
        }
        //判断是否有环
        if (IsCircle(M, N))
        { //有环，读取剩余输入，输出LOOP；
            for (int j = 0; j < S; j++)
            {
                cin >> si;
                for (int c = 0; c < si; c++)
                {
                    cin >> front;
                }
            }
            cout << "LOOP" << endl;
        }
        else
        { //无环
            for (int j = 0; j < S; j++)
            {
                cin >> si;
                for (int c = 0; c < M; c++)
                { //将输入值写入相应输入点
                    Eroad[c].val = inp[c][j];
                }
                for (int c = M; c < M + N; c++)
                { //初始化各元件输出值
                    Eroad[c].val = -1;
                }
                for (int c = 0; c < si; c++)
                { //输出结果
                    cin >> front;
                    cout << output(M + front - 1) << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}