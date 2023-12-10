# include <bits/stdc++.h>
# define N 100005
using namespace std;

long long l,k;
long long code[N];

long long check(long long x)
{
    //Ä£Äâ
    long long sum=0;
    long long cnt=0;
    for(long long i=1;i<=l;i++)
    {
        sum+=code[i];
        if(sum>=x) {cnt++;sum=0;}
        if(sum<=0) {sum=0;}
    }
    return cnt;
}

int main()
{
    cin>>l>>k;
    for(long long i=1;i<=l;i++) cin>>code[i];

    long long le=1,ri=1e15,mi;
    long long mn=-1,mx;
    while(le<=ri)
    {
        mi=(le+ri)/2;
        long long tmp=check(mi);
        if(tmp>k) le=mi+1;
        else if(tmp<k) ri=mi-1;
        else mn=mi,ri=mi-1;
        
    }
    if(mn==-1) {cout<<-1;return 0;}
    le=0,ri=1e15;
    while(le<=ri)
    {
        mi=(le+ri)/2;
        long long tmp=check(mi);
        if(tmp>k) le=mi+1;
        else if(tmp<k) ri=mi-1;
        else mx=mi,le=mi+1;
    }
    cout<<mn<<' '<<mx;
}
/* 
4 2
2
5
-3
9
 */