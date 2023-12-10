# include <bits/stdc++.h>
# define MAX_N 1000;
using namespace std;

int main()
{
    int months[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int start, end, n, cnt=0;
    cin>>start>>end;
    for(int i=1;i<=12;i++)
    {
        for(int j=0;j<=months[i-1];j++)
        {
            n=(i/10*1+i%10*10+j/10*100+j%10*1000)*10000+i*100+j;
            if(n>=start && n<=end) cnt++;
        }
    }
    cout<<cnt<<endl;
}