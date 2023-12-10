# include <bits/stdc++.h>
using namespace std;
int mat[40][40];
int main()
{
    int N;
    cin>>N;
    
    mat[0][N/2]=1;
    int x=0,y=N/2;
    for(int i=2;i<=N*N;i++)
    {
        if(x==0 && y!=N-1) {x=N-1;y=y+1;/* cout<<"a "; */}
        else if(y==N-1 && x!=0) {y=0;x=x-1;/* cout<<"b "; */}
        else if(x==0 && y==N-1) {x=x+1;/* cout<<"c "; */}
        else if(x!=0 && y!=N-1) {
            if(mat[x-1][y+1]==0) {x=x-1;y=y+1;}
            else {x=x+1;}
            /* cout<<"d "; */
        }
        mat[x][y]=i;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<mat[i][j]<<' ';
        }
        cout<<endl;
    }
}