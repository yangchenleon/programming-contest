# include <bits/stdc++.h>
# define MAX_N 1000;
using namespace std;
long long k[25][25][25];


long long w(long long a, long long b, long long c)
{
    if(a<=0 || b<=0 || c<=0) return 1;
    else if(a>20 || b>20 || c>20) return w(20,20,20);
    else if(k[a][b][c]) return k[a][b][c];
    else if(a<b && b<c) return k[a][b][c]=(w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c));
    else return k[a][b][c]=(w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1));
}

int main()
{
    long long a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a==-1 && b==-1 && c==-1)
            break;
        else
        { 
            printf("w(%lld, %lld, %lld) = ",a,b,c);
            cout<<w(a,b,c)%9223372036854775807<<endl;
        }
    }
    return 0;
}