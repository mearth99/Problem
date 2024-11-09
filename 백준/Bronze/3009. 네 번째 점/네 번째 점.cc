#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int x[3], y[3], seq_x, seq_y;

	scanf("%d%d%d%d%d%d", x, y, x+1, y+1,x+2,y+2);

	if (x[0] == x[1])
		seq_x = x[2];
	else if (x[1] == x[2])
		seq_x = x[0];
	else if (x[0] == x[2])
		seq_x = x[1];

	if (y[0] == y[1])
		seq_y = y[2];
	else if (y[1] == y[2])
		seq_y = y[0];
	else if (y[0] == y[2])
		seq_y = y[1];

	printf("%d %d", seq_x, seq_y);

	return 0;

}