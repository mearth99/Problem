//2661 좋은 수열

/* 문제
숫자 1, 2, 3으로만 이루어지는 수열이 있다. 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것이 있으면, 그 수열을 나쁜 수열이라고 부른다. 그렇지 않은 수열은 좋은 수열이다.
길이가 N인 좋은 수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 수열을 구하는 프로그램을 작성하라. 예를 들면, 1213121과 2123212는 모두 좋은 수열이지만 그 중에서 작은 수를 나타내는 수열은 1213121이다.
 */
/* 입력
입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다.
*/
/* 출력
첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 가장 작은 수를 나타내는 수열만 출력한다. 수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다.
*/
/* 예상
입력값은 오로지 N이고, N의 길이로 이루어진 수열 중, 가장 작은 수열을 구해야한다. 이렇기 때문에 backtracking을 사용하여 바닥에서 상위로 탐색하여 좋은 수열이 나오는 순간 바로 결과값을 출력하면 되겠다.
123123
*/
/* 결과
예상하던 방법으로 성공했지만, 시간이 오래소모되었다. 변수 초기화 등 실수가 너무 많았다. vscode에서 처음 디버깅을 시도했다. 앞으로는 코드 테스트하기 편하겠지..
미련하게 cout << 탈출!
*/
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <vector>
using namespace std;

int end_flag=0;

int check_bad(int idx, int goodlist[]){
  int temp[81];
  for(int i=0;i<81;i++){
    temp[i] = goodlist[i];
  }
  for(int i=1;i<=(idx+1)/2;i++){ //idx=8 i= 1,2,3,4 : 비교하는 갯수 
    int check = 0;
    for(int j=i-1; j>=0; j--)
      if(goodlist[idx-i-j]==goodlist[idx-j])
        check++;
    if(check==i)
      return 0;
    }
  return 1;
}
  



void good_sequence(int add,int idx, int count, int goodlist[]){
  if(end_flag)
    return;
  goodlist[idx] = add;
  if(check_bad(idx,goodlist)==1){
    if(idx==count){
    //여기서 가장 작은 좋은 수열이 있으면 출력해야합니다.
      for(int i=1;i<=idx;i++){
          cout << goodlist[i];
      }
      end_flag=1;
      return;
    }
    good_sequence(1,idx+1,count,goodlist);
    good_sequence(2,idx+1,count,goodlist);
    good_sequence(3,idx+1,count,goodlist);
  }else
    return;


}


int main()
{
  int goodlist[81] ={0};
  int n;
  cin >> n;
  good_sequence(1,1,n,goodlist);
}
