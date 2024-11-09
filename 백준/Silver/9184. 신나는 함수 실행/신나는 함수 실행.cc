#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
w(20, 20, 20)

if a < band b < c, then w(a, b, c) returns :
    w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)

    otherwise it returns :
w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)

을 재귀적 방식 말고 동적계획법으로 구현하시오.
*/

int main()
{
    int count = 0;
    int one=0, two=0, three=0;
    int list[21][21][21] = { 0 };

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            list[0][i][j] = 1;
            list[i][0][j] = 1;
            list[i][j][0] = 1;
        }
    }

    for (int a = 1; a < 21; a++)
    {
        for (int b = 1; b < 21; b++)
        {
            for (int c = 1; c < 21; c++)
            {
                if (a < b && b < c)
                {
                    list[a][b][c] = list[a][b][c - 1] + list[a][b - 1][c - 1] - list[a][b - 1][c];
                }
                else
                {
                    list[a][b][c] = list[a - 1][b][c] + list[a - 1][b - 1][c] + list[a - 1][b][c - 1] - list[a - 1][b - 1][c - 1];
                }
            }
        }
    }

    while (1)
    {
       
        scanf("%d %d %d", &one, &two, &three);
        if (one == -1 && two == -1 && three == -1)
            break;
       if (one <= 0 || two <= 0 || three <= 0)
        {
            printf("w(%d, %d, %d) = 1\n", one, two, three);
            continue;
        }
        else if (one > 20 || two > 20 || three > 20)
        {
            printf("w(%d, %d, %d) = 1048576\n", one, two, three);
        }
        else
        {
            printf("w(%d, %d, %d) = %d\n", one, two, three,list[one][two][three]);
        }
       
    }
    return 0;
}
