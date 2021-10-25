# include <bits/stdc++.h>
using namespace std;

int a[1005];

int main()
{
    int st,ed,n;
    int i=1,j=1;
    cin>>st>>ed>>n;
    
    a[0]=st;
    a[1]=ed;
    while(i<n)
    {
        int tmp=a[j-1]*a[j];
        //cout<<tmp<<endl;
        if(tmp<=9) {a[++i]=tmp;}
        else 
        {
            a[++i]=tmp/10;
            a[++i]=tmp%10;
        }
        j++;
    }
    for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d",a[i]);
    return 0;
}