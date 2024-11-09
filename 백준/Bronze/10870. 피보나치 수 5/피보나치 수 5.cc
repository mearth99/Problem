#include <stdio.h>

int main() {
    
    int num;
    scanf("%d",&num);
    int fato(int n);
    printf("%d",fato(num));
    return 0;
}

int fato(int num)
{
    if(num==1)
    return 1;
    else if(num==2)
    return 1;
    else if(num==0)
    return 0;
    else
    return fato(num-1)+fato(num-2);
    
}