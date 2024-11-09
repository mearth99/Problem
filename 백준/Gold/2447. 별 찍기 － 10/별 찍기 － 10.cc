#include <stdio.h>
#include <stdlib.h>
char space[2187][2187];
int main() {
	void star3(char space[2187][2187], int x, int y);
	void star9(char space[2187][2187], int x, int y);
	void star27(char space[2187][2187], int x, int y);
	void star81(char space[2187][2187], int x, int y);
	void star243(char space[2187][2187], int x, int y);
	void star729(char space[2187][2187], int x, int y);
	void star2187(char space[2187][2187], int x, int y);
	int input;
	

	scanf("%d", &input);
	

	if(input==3)
		star3(space, 0, 0);
	else if (input == 9)
		star9(space, 0, 0);
	else if (input == 27)
		star27(space, 0, 0);
	else if (input == 81)
		star81(space, 0, 0);
	else if (input == 243)
		star243(space, 0, 0);
	else if (input == 729)
		star729(space, 0, 0);
	else if (input == 2187)
		star2187(space, 0, 0);

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			printf("%c",space[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void empty(char space[2187][2187], int x, int y, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			space[y + i][x + j] = ' ';
		}
	}
	return;
}

void star3(char space[2187][2187], int x, int y)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			space[y + i][x + j] = '*';
			if(i==1 && j==1)
				space[y + i][x + j] = ' ';
		}
	}
	return;
}

void star9(char space[2187][2187], int x, int y)
{
	int n = 1, m = 1;

	for (int i = 0; i < 9; i++)
	{
		if (i == 1 || i == 4 || i == 7)
		{
			for (int j = 0; j < 9; j++)
			{
				if(j==1 || j==4 || j==7)
					space[y + i][x + j] = ' ';
				else
				space[y + i][x + j] = '*';
			}
		}
		else
			for (int j = 0; j < 9; j++)
			{	
				space[y + i][x + j] = '*';
			}
	}
	for (int i = 3; i < 6; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			space[y + i][x + j] = ' ';
		}
	}
	return;
}

void star27(char space[2187][2187], int x, int y)
{
	star9(space, x, y);
	star9(space, x, y + 9);
	star9(space, x, y + 18);
	star9(space, x + 9, y);
	star9(space, x + 9, y + 18);
	star9(space, x + 18, y);
	star9(space, x + 18, y + 9);
	star9(space, x + 18, y + 18);
	empty(space, x + 9, y + 9, 9);
	return;
}

void star81(char space[2187][2187], int x, int y)
{
	star27(space, x, y);
	star27(space, x, y + 27);
	star27(space, x, y + 54);
	star27(space, x + 27, y);
	star27(space, x + 27, y + 54);
	star27(space, x + 54, y);
	star27(space, x + 54, y + 27);
	star27(space, x + 54, y + 54);
	empty(space, x + 27, y + 27, 27);
	return;
}

void star243(char space[2187][2187], int x, int y)
{
	star81(space, x, y);
	star81(space, x, y + 81);
	star81(space, x, y + 162);
	star81(space, x + 81, y);
	star81(space, x + 81, y + 162);
	star81(space, x + 162, y);
	star81(space, x + 162, y + 81);
	star81(space, x + 162, y + 162);
	empty(space, x + 81, y + 81, 81);
	return;
}
void star729(char space[2187][2187], int x, int y)
{
	star243(space, x, y);
	star243(space, x, y + 243);
	star243(space, x, y + 486);
	star243(space, x + 243, y);
	star243(space, x + 243, y + 486);
	star243(space, x + 486, y);
	star243(space, x + 486, y + 243);
	star243(space, x + 486, y + 486);
	empty(space, x + 243, y + 243, 243);
	return;
}
void star2187(char space[2187][2187], int x, int y)
{
	star729(space, x, y);
	star729(space, x, y + 729);
	star729(space, x, y + 1458);
	star729(space, x + 729, y);
	star729(space, x + 729, y + 1458);
	star729(space, x + 1458, y);
	star729(space, x + 1458, y + 729);
	star729(space, x + 1458, y + 1458);
	empty(space, x + 729, y + 729, 729);
	return;
}