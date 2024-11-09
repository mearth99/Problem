#include <stdio.h>
#include <stdbool.h>
int array[10];
bool check[10]={false};


void cacu(int N, int M, int index)
{
    if(index==M)
    {
        for(int i=0;i<M;i++)
            printf("%d ",array[i]);
        printf("\n");
        return;
    }
    
    for(int i=1;i<=N;i++)
    {
        if(check[i])
            continue;
        check[i] = true;
        array[index] = i;
        cacu(N,M,index+1);
        check[i] = false;
    }
}


int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    cacu(N,M,0);
    return 0;
}