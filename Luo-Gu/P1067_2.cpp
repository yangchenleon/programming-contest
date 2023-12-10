# include <bits/stdc++.h>
using namespace std;

int main()
{
    /* 坑点如下：
    第一项前无‘+’号
    常数项与一次项是不同的概念
    注意系数为1，-1和0的情况 */
    int n,a;
    cin>>n;
    for(int i=n;i>0;i--) {
        cin>>a;
        if(a==0) continue;
        if(a<0) {
            cout<<'-';
            if(a!=-1) cout<<abs(a);
        }
        if(a>0) {
            if(i!=n) cout<<'+';
            if(a!=1) cout<<abs(a); 
        }
        //if(abs(a)!=1) cout<<abs(a);
        if(i==1) cout<<'x';
        else cout<<"x^"<<i;
    }
    cin>>a;
    if(a==0) return 0;
    else cout<<(a>0?'+':'-')<<abs(a);

    /* 大佬的是真的简介
    cin>>a;
    if(a){    //判0系数
        if(i!=n&&a>0)cout<<"+";    //根据正负、是否为最高此项决定加号
        if(abs(a)>1||i==0)cout<<a;    //输出系数（系数不为正负1或指数为0）
        if(a==-1&&i)cout<<"-";    //-1系数特判，常数项已特判
        if(i>1)cout<<"x^"<<i;    //二次及以上输出指数
        if(i==1)cout<<"x";    //一次项 */
}