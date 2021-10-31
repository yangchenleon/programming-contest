#include <stdio.h>
#include <stdlib.h>

typedef struct point{
	int x;
	int y;
	char type;
} point;

int main(int argc, char *argv[]) {
	int n, m;
	scanf("%d %d", &n, &m);
	point list[n];
	
	int i, j;
	int x, y;
	char type;
	for(i=0, j=n-1; j>=i;)
	{
		scanf("%d %d %c", &x, &y, &type);
		if(type == 'A')
		{
			list[i].x = x; list[i].y = y; list[i].type = type;
			i++;	
		}
		else
		{
			list[j].x = x; list[j].y = y; list[j].type = type;
			j--;
		}
	}
	int cnt = i;
	
	int tha0, tha1, tha2; 
	int judge;
	for(i=0; i<m; i++)
	{
		//printf("ff%d\n", i);
		int cnt1, cnt2;
		cnt1 = cnt2 = 0;
		scanf("%d %d %d", &tha0, &tha1, &tha2);
		//printf("%d %d %dhhh", tha0, tha1, tha2);
		for(j=0; j<cnt; j++)
		{
			judge = tha0 + list[j].x*tha1 + list[j].y*tha2;
			if(judge>0) cnt1++;
			else cnt2++;
		}	
		if(cnt1!=cnt && cnt2!=cnt) 
		{
			//printf("%d %d %d\n", cnt1, cnt2, cnt);
			printf("No\n");
			continue;
		}
		//else printf("YES\n");
		//else printf("sd");
		
		/**/
		//cnt1 = cnt2 = 0;
		for(; j<n; j++)
		{
			judge = tha0 + list[j].x*tha1 + list[j].y*tha2;
			if(judge>0) cnt1++;
			else cnt2++;
		}
		if(cnt1==cnt || cnt2==cnt) printf("Yes\n");
		else printf("No\n");
		
	}
	return 0;
}
/*
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
-3 1 1
0 2 -3
-3 0 2
9 1
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
-3 0 2
*/
