#include <stdio.h>

int main() {
    int input, min = -1;
    scanf("%d",&input);
    for(int i=1;i<=input;i++)
    {
        int sum=i;
        int num=i;
        while(num>0)
        {
            sum=sum+num%10;
            num=num/10;
        }
        
        if(sum==input)
        {
            min=i;
            break;
        }
    }
    if(min==-1)
    printf("0");
    else
    printf("%d",min);
}