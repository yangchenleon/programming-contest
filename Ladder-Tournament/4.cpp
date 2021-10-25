# include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    double M,P;
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>P;
        if(P<M) 
            printf("On Sale! %.1f\n",P);
    }
    return 0;
}