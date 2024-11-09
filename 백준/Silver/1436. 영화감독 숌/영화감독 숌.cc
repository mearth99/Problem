#include <stdio.h>

int main() {
    int input, count=0;
    scanf("%d",&input);
    for(int i=666;i>0;i++)
    {
         if(count==input)
        {
            printf("%d",i-1);
            break;
        }
        if(i%10==6)
        {
            if(i/10%10==6)
                if(i/100%10==6)
                {
                    count++;
                    continue;
                }
        }
         if(i/10%10==6)
        {
            if(i/100%10==6)
                if(i/1000%10==6)
                {
                    count++;
                    continue;
                }
        }
         if(i/100%10==6)
        {
            if(i/1000%10==6)
                if(i/10000%10==6)
                 {
                    count++;
                    continue;
                }
        }
        if(i/1000%10==6)
        {
            if(i/10000%10==6)
                if(i/100000%10==6)
                      {
                    count++;
                    continue;
                }
        }
         if(i/10000%10==6)
        {
            if(i/100000%10==6)
                if(i/1000000%10==6)
                     {
                    count++;
                    continue;
                }
        }
        
        
       
    }
    return 0;
}