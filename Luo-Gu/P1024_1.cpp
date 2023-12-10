# include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    int cnt=0;
    for(double i=-100;i<100;i++)
    {
        double l=i;
        double r=l+1;
        double y1=a*l*l*l+b*l*l+c*l+d;
        double y2=a*r*r*r+b*r*r+c*r+d;
        if(y1==0) {cnt++;printf("%.2lf ",l);}
        else if(y1*y2<0) 
        {
            while(r-l>=0.001)
            {
                double m=(l+r)/2;
                double ym=a*m*m*m+b*m*m+c*m+d;
                if(ym*y1<=0)
                    r=m;
                else 
                    l=m;
            }
            printf("%.2lf ",r);
            cnt++;
        }
        if(cnt==3) break;
    }
}