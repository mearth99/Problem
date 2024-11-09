//10867 중복빼고 정렬

/* 문제
 */
/* 입력
*/
/* 출력
*/
/* 예상
123123
*/
/* 결과
*/
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <vector>
using namespace std;

int main()
{
  int N,temp,flag=0;
  int number[1001] = {0};
  int negetive[1001] = {0};
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> temp;
    if(temp<0)
      negetive[(temp*-1)]++;
    else
      number[temp]++;
  }
  for(int i=1000;i>=1;i--){
    if(negetive[i]>0&&flag==1)
      cout<< " " << (i*-1);
    else if(negetive[i]>0){
      flag=1;
      cout<<(i*-1);
    }
  }
  for(int i=0;i<=1000;i++){
    if(number[i]>0&&flag==1)
      cout<< " " << i;
    else if(number[i]>0){
      flag=1;
      cout<<i;
    }
  }
}
