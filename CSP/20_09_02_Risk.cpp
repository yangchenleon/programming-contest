#include <iostream>
using namespace std;

int main()
{
   int n,k,t;
   int xl,yd,xr,yu;
   cin >> n >> k >> t >> xl >> yd >> xr >> yu;
   int i, j;
   int cnt1=0,cnt2=0; //经过和高危人数
   for(i=0;i<n;i++)
   {
      int x, y; //经过点坐标
      int sign1, sign2; //经过信号和高危报警
      int cnt; //记录连续次数
      cnt = sign1 = sign2=0;
      for(j=0;j<t;j++)
      {
         cin >> x >> y;
         if(x>=xl&&x<=xr&&y>=yd&&y<=yu)
         {
             sign1=1; //但凡在高位区，就记录
             if(sign2==0) {sign2=1;cnt=1;} //初始或者重置
             else cnt++; //若连续则继续记录
         }
         else
            if(cnt<k) sign2=0; //若已经连续在高位区，则不管之后情况
      }
      if(sign1==1) cnt1++;
      if(cnt>=k) cnt2++;
   }
   cout << cnt1 << endl;
   cout << cnt2 << endl;
   return 0;
}