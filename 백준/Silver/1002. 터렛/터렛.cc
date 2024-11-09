#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	/*
	원
	0: 만나지 않는다.
	1: 접점이 생긴다.
	2: 원이 겹친다.
	무한. 원이 동치다.
	*/
	int repeat,x1,y1,x2,y2,r1,r2;
	int decide(int x1, int y1, int r1, int x2, int y2, int r2);
	scanf("%d", &repeat);
	
	while (repeat)
	{
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);

		printf("%d\n", decide(x1, y1, r1, x2, y2, r2));
		repeat--;
	}
}

int decide(int x1, int y1, int r1, int x2, int y2, int r2)
{
	if (x1 - x2 == 0 && y1 - y2 == 0 && r1 - r2 == 00)
		return -1;
	else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < (r1 - r2)*(r1 - r2))
		return 0;
	else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) == (r1 - r2)*(r1 - r2))
		return 1;
	else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) == (r1 + r2)*(r1 + r2))
		return 1;
	else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) >= (r1 + r2)*(r1 + r2))
		return 0;
	else
		return 2;
}