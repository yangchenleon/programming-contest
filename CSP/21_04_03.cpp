#include <bits/stdc++.h>
using namespace std;

int N,Tdef,Tmax,Tmin;
string H;
int n;

typedef struct{
    int state=0;//未分配、占用、过期、待分配
    string zyz="null";
    int timer=0;
} ipstate;

ipstate ip[1001];

typedef struct{
    string snt;
    string rev;
    string type;
    int ip;
    int et;
} Potocal;

void process(int st, Potocal p)
{
    /* 不处理情况 */
    if(!(p.rev=="*"||p.rev==H)&&p.type!="REQ") return;
    if(p.rev=="*"&&p.type!="DIS") return;
    if(p.rev==H&&p.type=="DIS") return;

    /* 预先检查：处理超时定时器 */
    for(int i=1;i<=N;i++)
    {
        if(ip[i].state==3&&ip[i].timer<st)
        {
            //cout<<"zhanyong1"<<endl;
            ip[i].state=0;
            ip[i].zyz="null";
        }
        if(ip[i].state==1&&ip[i].timer<st)
        {
            //cout<<"zhanyong2"<<endl;
            ip[i].state=2;
        }
    }

    if(p.type=="DIS")
    {
        int cip=0;
        bool flag=0;
        for(int i=1;i<=N;i++)
        {
            if(ip[i].zyz==p.snt) {cip=i;flag=1;break;}
        }
        if(!flag)
        {
            for(int i=1;i<=N;i++)
            {
                if(ip[i].state==0) {cip=i;flag=1;break;}
            }
        }
        if(!flag)
        {
            for(int i=1;i<=N;i++)
            {
                if(ip[i].state==2) {cip=i;flag=1;break;}
            }
        }


        if(cip==0) return;
        else
        {
            ip[cip].state=3;
            ip[cip].zyz=p.snt;

            if(p.et==0) ip[cip].timer=st+Tdef;
            else if(p.et-st<=Tmin) ip[cip].timer=st+Tmin;
            else if(p.et-st>=Tmax) ip[cip].timer=st+Tmax;
            else ip[cip].timer=p.et;
            //cout<<"\t\t"<<cip<<ip[cip].zyz<<endl;
            cout<<H<<' '<<p.snt<<' '<<"OFR"<<' '<<cip<<' '<<ip[cip].timer<<endl;
        }
    }

    if(p.type=="REQ")
    {
        int cip=p.ip;
        if(p.rev!=H)
        {
            if(ip[cip].state==3)
            {
                ip[cip].state=0;
                ip[cip].zyz="null";
                //cout<<"\t\t"<<"aaa"<<endl;
                return;
            }
        }
        else
        {
            //cout<<cip<<ip[cip].zyz<<endl;
            if(!(cip>=1&&cip<=N&&ip[cip].zyz==p.snt))
            {
                cout<<H<<' '<<p.snt<<' '<<"NAK"<<' '<<cip<<' '<<0<<endl;
                return;
            }
            else
            {
                ip[cip].state=1;
                if(p.et==0) ip[cip].timer=st+Tdef;
                else if(p.et-st<=Tmin) ip[cip].timer=st+Tmin;
                else if(p.et-st>=Tmax) ip[cip].timer=st+Tmax;
                else ip[cip].timer=p.et;
                cout<<H<<' '<<p.snt<<' '<<"ACK"<<' '<<cip<<' '<<ip[cip].timer<<endl;
            }
        }
    }

}

int main()
{
    cin>>N>>Tdef>>Tmax>>Tmin>>H;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int stime;
        Potocal poto;
        cin>>stime>>poto.snt>>poto.rev>>poto.type>>poto.ip>>poto.et;
        process(stime,poto);
    }
    return 0;
}
/*
4 5 10 5 dhcp
1
1 a * DIS 0 0

4 5 10 5 dhcp
16
1 a * DIS 0 0
2 a dhcp REQ 1 0
3 b a DIS 0 0
4 b * DIS 3 0
5 b * REQ 2 12
6 b dhcp REQ 2 12
7 c * DIS 0 11
8 c dhcp REQ 3 11
9 d * DIS 0 0
10 d dhcp REQ 4 20
11 a dhcp REQ 1 20
12 c dhcp REQ 3 20
13 e * DIS 0 0
14 e dhcp REQ 2 0
15 b dhcp REQ 2 25
16 b * DIS 0 0
*/
