# include <iostream>
# include <algorithm>
# include <stack>
using namespace std;

int main()
{
    int n;
    stack<int> s;
    cin>>n;
    while(n!=0)
    {
        s.push(n);
        cin>>n;
    }
    while(!s.empty())
    {
        n = s.top();
        s.pop();
        cout<<n<<' ';
    }
    
}