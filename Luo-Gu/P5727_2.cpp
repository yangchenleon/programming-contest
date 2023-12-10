# include <iostream>
# include <algorithm>
# define MAX_N 150
using namespace std;

int main()
{
    int s[MAX_N];
    int j=0;

    int n;
    cin>>n;
    s[j++]=n;
    while(n!=1)
    {
        if(n%2) s[j++] = n = n*3+1;
        else s[j++] = n = n/2;
    }
    j--;

    do {
        cout<<s[j]<<' ';
    }while(j--!=0);
}