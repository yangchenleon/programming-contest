# include <bits/stdc++.h>
using namespace std;

int n,r,q;
int a[200100],win[200100],lose[200100]; //a[0]���ڼ��������洢��win[0],lose[0]���浱ǰ����
int s[200100],w[200100];

bool cmp(int x,int y) //˭��˭Ӯ
{
    if(s[x]==s[y]) return x<y;
    else return s[x]>s[y];
}

void merge()
{
    int i,j;
    i=j=1,a[0]=0;
    while(i<=win[0] && j<=lose[0])
    {
        if(cmp(win[i],lose[j]))
            a[++a[0]]=win[i++];
        else
            a[++a[0]]=lose[j++];
    }
    while(i<=win[0]) a[++a[0]]=win[i++];
    while(j<=lose[0]) a[++a[0]]=lose[j++];        
}

int main()
{
    cin>>n>>r>>q; n*=2;
    for(int i=1;i<=n;i++) a[i]=i;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>w[i];
    sort(a+1,a+n+1,cmp);
    
    for(int i=1;i<=r;i++) //ÿһ�ַ�Ӯ�ĺ���Ķ���
    {
        win[0]=lose[0]=0;
        for(int j=1;j<=n;j+=2) 
        {
            if(w[a[j]]>w[a[j+1]]) {
                s[a[j]]++;
                win[++win[0]]=a[j];
                lose[++lose[0]]=a[j+1];
            }
            else {
                s[a[j+1]]++;
                win[++win[0]]=a[j+1];
                lose[++lose[0]]=a[j];
            }
        }
        merge(); //����ͼ�λ����� ����������������������ǰ��
    }
    cout<<a[q];
    return 0;
    //���ϣ��鲢�ʺϹ鲢���������ͻ������������
}

/* ����Ϊ֮ǰд�ϵģ���;�鿴��ⷢ�ֻᳬʱ��Ӧ��ʹ�ù鲢����
# include <bits/stdc++.h>
using namespace std;

typedef struct {
    int n,s,w;
} spt;

bool cmp(spt a, spt b)
{
    if(a.s==b.s) return a.n<b.n;
    else return a.s>b.s;
}

int main()
{
    int N,R,Q;
    cin>>N>>R>>Q; //2*N��ѡ�֣�R��֮������Qѡ�ֵı��
    spt k[2*N];
    for(int i=0;i<=2*N;i++)
    {
        cin>>k[i].s;
        k[i].n=i+1;
    }
    for(int i=0;i<=2*N;i++)
    {
        cin>>k[i].w;
    }
    for(int i=0;)
} */