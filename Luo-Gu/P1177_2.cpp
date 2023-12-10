# include <bits/stdc++.h>
using namespace std;
int a[100001],n;

void qsort(int l,int r)//应用二分思想
{
    int mid=a[(l+r)/2];//中间数
    int i=l,j=r;
    do{
        while(a[i]<mid) i++;//查找左半部分比中间数大的数
        while(a[j]>mid) j--;//查找右半部分比中间数小的数
        if(i<=j)//如果有一组不满足排序条件（左小右大）的数
        {
            swap(a[i],a[j]);//交换
            i++;
            j--;
        }
    }while(i<=j);//这里注意要有=
    if(l<j) qsort(l,j);//递归搜索左半部分
    if(i<r) qsort(i,r);//递归搜索右半部分
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    qsort(1,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}

/*  
他妈的最好不要碰指针，搞不灵清还容易错
标答是有干净又好理解
void my_swap(int *a, int *b)
{
    if(a==b) return ;
    int tmp;
    tmp=*a;*a=*b;*b=tmp;
}


void my_qsort(int *a, int *b)
{
    int mid=*a;
    int pos=0;
    for(int i=1;i<b-a;i++) {
        if(a[i]<=mid) {pos++;my_swap(a+pos,a+i);}
    }
    my_swap(a+pos,a);
    if(pos>=2)my_qsort(a,a+pos); //这里填1也可以
    if(b-a-pos-1>=2)my_qsort(a+pos+1,b);
} 

int main()
{
    int N;
    cin>>N;
    int k[N];
    for(int i=0;i<N;i++)
    {
        cin>>k[i];
    }
    my_qsort(k,k+N);
    for(int i=0;i<N;i++)
    {
        cout<<k[i]<<' ';
    }
}
*/