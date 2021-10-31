#include <iostream>
#include <algorithm>
using namespace std;

bool isseven(int num)
{
   if(num%7==0) return true; //7的倍数
   while(num) //位数含7
   {
      if(num%10==7) return true;
      else num=num/10;
   }
   return false;
}

int main()
{
   int total, cnt=0; //总数和计数
   int pep[4]={0}; //每个人跳过计数
   int num=1; //被判断数字
   cin>>total;
   while(cnt<total)
   {
      if(isseven(num)) pep[(num-1)%4]++;
      else cnt++;
      num++;
   }
   printf("%d\n%d\n%d\n%d\n",pep[0],pep[1],pep[2],pep[3]);
}