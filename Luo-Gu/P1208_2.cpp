# include <bits/stdc++.h>
using namespace std;

typedef struct {
    int price;
    int num;
} farmer;

bool cmp(farmer a, farmer b)
{
    if(a.price==b.price) return a.num>b.num;
    else return a.price<b.price;
}

int main()
{
    int n,m;
    int cnt=0,money=0;
    cin>>n>>m;
    farmer farmers[m];
    for(int i=0;i<m;i++)
    {
        cin>>farmers[i].price>>farmers[i].num;
    }
    sort(farmers,farmers+m,cmp);
    for(int i=0;i<m;i++)
    {
        if(farmers[i].num+cnt<=n)
        {
            cnt+=farmers[i].num;
            money+=farmers[i].num*farmers[i].price;
        }
        else
        {
            money+=(n-cnt)*farmers[i].price;
            break;
        }
    }
    cout<<money;
    return 0;
}
/*
100 5
5 20
9 40
3 10
8 80
6 30
*/