#include <stdio.h>
void solve(int n, int x, int y) {
	if (n == 0) return;
	//x+y+z=6 - > 6-x-y = z;
	solve(n - 1, x, 6 - x - y);
	//n번째 탑
	printf("%d %d\n", x, y);
	solve(n - 1, 6 - x - y, y);

}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	solve(n, 1, 3);
	return 0;
}