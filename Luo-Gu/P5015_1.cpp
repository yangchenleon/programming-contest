# include <bits/stdc++.h>
# define MAX_N 1000;
using namespace std;

int main()
{
    char c;
    int cnt=0;
    while((c=getchar())!='\n') {
        if(c!=' ')
            cnt++;
    }
    cout<<cnt;
}