# include <bits/stdc++.h>
# define MAX_N 1000;
using namespace std;

long long ans[100010];

long long count(int n, int k)
{
    /* ���ans mod 100003 */
    if(n==0) return 1;
    if(n==1) return 1; //�ݹ����
    if(ans[n]) return ans[n];
    else if(n<=k) {
        long long sum=0;
        for(int i=1;i<=n;i++) {
            sum+=count(n-i,k);
        }
        return ans[n]=sum%100003;
    }
    else {
        long long sum=0;
        for(int i=1;i<=k;i++) {
            sum+=count(n-i,k);
        }
        return ans[n]=sum%100003;
    }
}

int main()
{
    /* �ݹ飬����˼�� + ���仯���� */
    int n,k;
    cin>>n>>k;
    cout<<count(n,k)<<endl;
}