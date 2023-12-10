#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int a[205],f[205][205],l[205][205],s[205],n,minn,maxx;
int main()
{
	memset(f,127/3,sizeof(f));
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  {
	  	scanf("%d",&a[i]);
	  	s[i]=s[i-1]+a[i];
	  	f[i][1]=0;
	  }

	for (int i=n+1;i<=n*2;i++)
	  {
	  	s[i]=s[i-1]+a[i-n];//复制一遍
	  	f[i][1]=0;
	  }
	  
	//处理完输入开始计算状态转移方程
	 
	for (int len=2;len<=n;len++)//长度
	  for (int i=1;i<=n*2-len;i++)//前面的数，n-len+1+n-1=n*2-len
	    for (int k=1;k<len;k++)//分界线
		  {
		f[i][len]=min(f[i][len],f[i][k]+f[i+k][len-k]+s[i+len-1]-s[i-1]);
l[i][len]=max(l[i][len],l[i][k]+l[i+k][len-k]+s[i+len-1]-s[i-1]);
		  }
	minn=2147483647;
	for (int i=1;i<=n;i++)
	  {
	  	minn=min(minn,f[i][n]);
	  	maxx=max(maxx,l[i][n]);
	  }
	printf("%d\n%d\n",minn,maxx);
}