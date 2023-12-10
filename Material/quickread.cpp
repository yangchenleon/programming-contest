#include<cstdio>
inline int read(){//??
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x*f;
}
int read()//¿ì¶Á
{
	int x=0;
	char s=getchar();
	while(s>'9'||s<'0') s=getchar();
	while(s<='9'&&s>='0') x=x*10+s-'0',s=getchar();
	return x;
}