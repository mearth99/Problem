#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int x, y, h, w,l_x,l_y;
	scanf("%d%d%d%d", &x, &y, &w, &h);

	if (w - x < x)
		l_x = w - x;
	else
		l_x = x;
	if (h - y < y)
		l_y = h - y;
	else
		l_y = y;

 	if (l_x <= l_y)
		printf("%d", l_x);
	else
		printf("%d", l_y);


	return 0;

}