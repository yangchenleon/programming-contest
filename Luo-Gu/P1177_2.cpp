# include <bits/stdc++.h>
using namespace std;
int a[100001],n;

void qsort(int l,int r)//Ӧ�ö���˼��
{
    int mid=a[(l+r)/2];//�м���
    int i=l,j=r;
    do{
        while(a[i]<mid) i++;//������벿�ֱ��м��������
        while(a[j]>mid) j--;//�����Ұ벿�ֱ��м���С����
        if(i<=j)//�����һ�鲻����������������С�Ҵ󣩵���
        {
            swap(a[i],a[j]);//����
            i++;
            j--;
        }
    }while(i<=j);//����ע��Ҫ��=
    if(l<j) qsort(l,j);//�ݹ�������벿��
    if(i<r) qsort(i,r);//�ݹ������Ұ벿��
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    qsort(1,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}

/*  
�������ò�Ҫ��ָ�룬�㲻���廹���״�
������иɾ��ֺ����
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
    if(pos>=2)my_qsort(a,a+pos); //������1Ҳ����
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