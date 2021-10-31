#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
	int idx;
	int val;
} vector; 

int main(int argc, char *argv[]) {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	//printf("ds");
	vector v[a];
	
	int i, j=0;
	long long int sum =0;
	int index, value;
	
	for(i=0; i<a; i++)
	{
		//printf("fdsf");
		scanf("%d %d", &index, &value);
		v[i].idx = index; v[i].val = value;
	}
	for(i=0; i<b; i++)
	{
		scanf("%d %d", &index, &value);
		for(; j<a; j++)
			if(index == v[j].idx)
			{
				sum += value * v[j].val;
				break;
			}
				
	}
	
	printf("%lld\n", sum);
	return 0;
}