#include <iostream>
#define MAX_N 1000
using namespace std;
int n, m, k[MAX_N];
bool binary_search(int x) {
    //x的存在范围是k[l]到k[r-1]
    int l = 0, r = n;
    
    //反复操作指导存在范围为空
    while(r-1>=1){
        int i = (l+r)/2;
        if(k[i]==x) return true; //找到x
        else if (k[i]<x) l=i+1;
        else r=i;
    }

    //没找到x
    return x;
}

int main()
{
    cout<<"臭傻逼";
    getchar();
    return 0;
} 