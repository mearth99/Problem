#include <stdio.h>
#include <stdlib.h>

int main() {
    //에라노스의 체를 이용하여 소수 구하기
    
    int n,m;
    int *pnum;
    scanf("%d%d",&m,&n);
    
    pnum = (int *)malloc(sizeof(int)*(n+1)); //0~n까지 메모리 할당함.
    
    *(pnum+0) = 0;
    *(pnum+1) = 0;
    
    for(int i=2;i<=n;i++)
    {
        *(pnum+i)=i;
    }
    
    for(int i=2;i<=n;i++)
    {
        if(*(pnum+i)==0)
            continue;
        if(*(pnum+i)%i==0)
        {
            for(int j=2;i*j<=n;j++)
            {
                *(pnum+i*j)=0;
            }
        }
        
    }
    for(int i=m;i<=n;i++)
    {
        if(*(pnum+i)!=0)
        printf("%d\n",*(pnum+i));
    }
    return 0;
}