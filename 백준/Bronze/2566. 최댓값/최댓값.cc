//1645 랜선자르기
 /* 입력
첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다. 
K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 그리고 항상 K ≦ N 이다. 
그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 231-1보다 작거나 같은 자연수이다.
 */

 /* 출력
첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다.
 */

/* 예상

*/
/* 결과
    
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int array[9][10];

int main()
{
  int max=-1;
  int a[2] = {1,1};
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
     scanf("%d",&array[i][j]); 
    }
  }
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(array[i][j]>max){
        max =  array[i][j];
        a[0] = i+1;
        a[1] = j+1;
       }
    }
  }
  printf("%d\n",max);
  printf("%d %d",a[0],a[1]);
}
