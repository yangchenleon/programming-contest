#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int n,a[200],plan;
void dfs(int x){
    if(x>n){
        plan++;
        return;
    }
    for(int i=1;i<=n;i++){
        a[x]=i;
        int flag=0;
        for(int j=1;j<=x-1;j++){
            if(a[x] == a[j] || fabs(x-j)==fabs(a[x]-a[j])){
                flag=1;
                break;
            }
        }
        if(flag==0)
            dfs(x+1);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        plan=0;
        for(int i=1;i<20;i++)
            a[i]=0;
         dfs(1);
         cout<<plan<<endl;
    }
    return 0;
}

