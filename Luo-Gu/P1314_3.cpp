# include <bits/stdc++.h>
# define N 200010
using namespace std;
long long w[N],v[N];
long long l[N],r[N];
long long n,m,s,ans;
long long mx=-1,mn=2147483647;
long long sum_gtw[N], sum_v[N];

long long calu(long long w[],long long v[],long long l[],long long r[],long long W)
{
    long long sum=0;
    memset(sum_gtw,0,sizeof(sum_gtw));
	memset(sum_v,0,sizeof(sum_v));
    for(int i=1;i<=n;i++)
    {
        if(w[i]>=W) {sum_gtw[i]=sum_gtw[i-1]+1;sum_v[i]=sum_v[i-1]+v[i];}
        else {sum_gtw[i]=sum_gtw[i-1];sum_v[i]=sum_v[i-1];}
    }
    for(int i=1;i<=m;i++)
    {
        sum+=(sum_gtw[r[i]]-sum_gtw[l[i]-1])*(sum_v[r[i]]-sum_v[l[i]-1]);
    }
    return sum;
}

int main()
{
    cin>>n>>m>>s;
    for(long long i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
        mx=max(mx,w[i]);
		mn=min(mn,w[i]);
    }
    long long right=mx+2, left=mn-1;
    for(long long i=1;i<=m;i++)
        cin>>l[i]>>r[i];
    long long ans=0x3f3f3f3f3f3f3f3f;
    while(left<=right)
    {
        long long mid=(left+right)/2;
        long long y=calu(w,v,l,r,mid);
        //cout<<y<<endl;
        if(y-s>0)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
        ans=min(llabs(y-s),ans);
    }

    cout<<ans<<endl;
}
/* 
5 3 15                    
1 5 
2 5
3 5
4 5
5 5
1 5
2 4
3 3 
answer
10
 */