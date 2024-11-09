#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
   long long int list[101] = { 0 };
    int N,n;


    list[0] = 1;
    list[1] = 1;
    list[2] = 1;
    for (int j = 3; j <= 100; j++)
    {
        list[j] = (list[j - 2] + list[j - 3]);
    }

    scanf("%d", &N);
    for (int i = 0; i < N-1; i++)
    {
        scanf("%d", &n);
     
        printf("%lld\n", list[n-1]);
    }
    scanf("%d", &n);
    printf("%lld", list[n-1]);
    return 0;
}
