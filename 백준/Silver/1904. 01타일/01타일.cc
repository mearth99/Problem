#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int Factorial(int list[],int i)
{
    list[0] = 1;
    list[1] = 1;
    for (int j = 2; j <= i; j++)
    {
        list[j] = (list[j - 1] + list[j - 2])%15746;
    }
    return list[i];
}


int main()
{
    int* list;
    int N;
    int cost;
    scanf("%d", &N);
    list = (int*)malloc(sizeof(int)*(N + 1));
    cost=Factorial(list, N);
    printf("%d", cost);
    return 0;
}
