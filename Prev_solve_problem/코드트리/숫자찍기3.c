#include "stdio.h"
int tranigle[101][101] = {0};

void first(int height){
    int i,j;
    for(i=1;i<=height;i++){
        for(j=1;j<=i;j++){
            if(j==1 || j==i)
                tranigle[i][j] = 1;
            else
                tranigle[i][j] = tranigle[i-1][j-1] + tranigle[i-1][j]; 
        }
    }
    for(i=1;i<=height;i++){
        for(j=1;j<i;j++){
            printf("%d ",tranigle[i][j]);
        }
        printf("%d\n",tranigle[i][j]);
    }

    return;
}
void second(int height){
    int i,j;
    for(i=1;i<=height;i++){
        for(j=1;j<=i;j++){
            if(j==1 || j==i)
                tranigle[i][j] = 1;
            else
                tranigle[i][j] = tranigle[i-1][j-1] + tranigle[i-1][j]; 
        }
    }
    for(i=height;i>=1;i--){
        for(j=height;j>=1;j--){
            if(tranigle[i][j])
              printf("%d ",tranigle[i][j]);
            else
              printf(" ");
        }
        printf("\n");
    }
    return;
}
void third(int height){
  int i,j;
    for(i=1;i<=height;i++){
        for(j=1;j<=i;j++){
            if(j==1 || j==i)
                tranigle[i][j] = 1;
            else
                tranigle[i][j] = tranigle[i-1][j-1] + tranigle[i-1][j]; 
        }
    }
    for(i=height;i>=1;i--){
        for(j=height;j>=i;j--){
            printf("%d ",tranigle[j][i]);
        }
        printf("\n");
    }
    
}
int main() {
    // 여기에 코드를 작성해주세요.
    int height, type;
    scanf("%d %d", &height, &type);
    if(type==1){
        first(height);
    }else if(type==2){
        second(height);
    }
    else if(type==3){
        third(height);
    }
    return 0;
}