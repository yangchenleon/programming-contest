#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
   int x, y; //监测点坐标
   int index; //监测点编号
   int dis; //监测点距离
} point;

bool cmp(point a, point b)
{
   if(a.dis==b.dis) return a.index<b.index;
   else return a.dis<b.dis;
}

int main(void)
{
   int i;
   int n,X,Y;
   cin>>n>>X>>Y; //监测点总数和市民所在位置
   point pos[n];
   for(i=0;i<n;i++)
   {
      cin>>pos[i].x>>pos[i].y;
      pos[i].index=i+1;
      pos[i].dis=(pos[i].x-X)*(pos[i].x-X)+(pos[i].y-Y)*(pos[i].y-Y); //距离居民的位置
   }
   sort(pos,pos+n,cmp); //根据距离排序
   for(i=0;i<3;i++)
      cout<<pos[i].index<<endl;
   return 0;
}