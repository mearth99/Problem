#include <stdio.h>
#include <stdlib.h>

int main() {
    //에라노스의 체를 이용하여 소수 구하기
    int n,seq;
    int *pnum;
    while(1)
    {
        seq=0;
        scanf("%d",&n);
        if(n==0)
            break;    
        pnum = (int *)malloc(sizeof(int)*(2*n+1)); //0~n까지 메모리 할당함.
        
        *(pnum+0) = 0;
        *(pnum+1) = 0;
        
        for(int i=2;i<=2*n;i++)
        {
            *(pnum+i)=i;
        }
        
        for(int i=2;i<=2*n;i++)
        {
            if(*(pnum+i)==0)
                continue;
            if(*(pnum+i)%i==0)
            {
                for(int j=2;i*j<=2*n;j++)
                {
                    *(pnum+i*j)=0;
                }
            }
            
        }
        for(int i=n+1;i<=2*n;i++)
        {
            if(*(pnum+i)!=0)
                seq++;
        }
        printf("%d\n",seq);
        free(pnum);
    }
    return 0;
}