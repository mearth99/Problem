#include<stdio.h>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>

int main()
{
	double r;
	scanf("%lf", &r);

	printf("%lf\n%lf", r*r*M_PI, r*r*2);

	return 0;

}