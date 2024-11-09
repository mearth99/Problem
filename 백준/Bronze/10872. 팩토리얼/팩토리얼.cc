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
    else if(num==0)
    return 1;
    else
    return num*fato(num-1);
    
}