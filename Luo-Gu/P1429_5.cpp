# include <bits/stdc++.h>
using namespace std;

const int INF = 2 << 20;

typedef struct {
    double x,y;
} point;

point S[200005];
int temp[200005];

double dist(int i,int j)
{
    double x = (S[i].x - S[j].x) * (S[i].x - S[j].x);
    double y = (S[i].y - S[j].y) * (S[i].y - S[j].y);
    return sqrt(x + y);
}

bool cmp(point a, point b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}

double solve(int le, int ri)
{
    if(le==ri) return INF;
    if(le+1==ri) return dist(le,ri);

    int mi=(le+ri)/2;
    double lmax=solve(le,mi);
    double rmax=solve(mi+1,ri);
    double d=min(lmax,rmax);

    int k = 0;
    for(int i=le;i<=ri;i++)
        if(abs(S[mi].x - S[i].x) < d)
            temp[k++] = i;
    for(int i=0;i<k;i++)
    {
        for(int j=i+1;j<k;j++) 
		{
            if(abs(S[temp[j]].y-S[temp[i]].y)<d)
            {
                double td = dist(temp[i], temp[j]);
                if(d > td) d = td;
            }
        }
    }
    return d;
}

int main()
{
    int n;
    cin>>n;    
    for(int i=0;i<n;i++)
        cin>>S[i].x>>S[i].y;
    sort(S,S+n,cmp);
    double d=solve(0,n-1);
    printf("%.4f",d);
}
/*
3
1 1
1 2
2 2
*/