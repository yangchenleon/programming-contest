# include <bits/stdc++.h>
using namespace std;

typedef struct {
    string name;
    int score1;
    int score2;
    char GB;
    char XB;
    int paper;
    int money;
} stu;

int count(stu a)
{
    int money=0;
    if(a.score1>80 && a.paper>=1) money+=8000;
    if(a.score1>85 && a.score2>80) money+=4000;
    if(a.score1>90) money+=2000;
    if(a.score1>85 && a.XB=='Y') money+=1000;
    if(a.score2>80 && a.GB=='Y') money+=850;
    return money;
}

int main()
{
    int n, sum=0, max=0;
    string name;
    cin>>n;
    stu k[n];
    for(int i=0;i<n;i++)
    {
        cin>>k[i].name>>k[i].score1>>k[i].score2>>k[i].GB>>k[i].XB>>k[i].paper;
        sum+=(k[i].money=count(k[i]));
        if(k[i].money>max) {
            max=k[i].money;
            name=k[i].name;
        }
    }
    cout<<name<<endl<<max<<endl<<sum;
}