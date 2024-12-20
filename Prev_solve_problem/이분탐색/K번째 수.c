//1300 K번쨰 수

 /* 입력
첫째 줄에 배열의 크기 N이 주어진다. N은 105보다 작거나 같은 자연수이다. 둘째 줄에 k가 주어진다. k는 min(109, N2)보다 작거나 같은 자연수이다.
 */

 /* 출력
B[k]를 출력한다.
 */

/* 예상
보통 1초 = 1억의 단순한 연계가 가능하고, 이 문제는 시간을 2초 요구하기에 2억의 계산 이내로 해결해야한다. 그런데, N이 10^10까지 갈 수 있기 때문에 
일반적인 정렬인 NlogN으로 사용 시 10억의 최대 계산결과가 나타난다. 따라서 정렬 이외의 방법으로 해결해야하며, 그 방법이 바로 이분탐색이다.

이분탐색으로 탐색하면, B[K]는 결국 자신보다 같거나 작은 수가 K만큼 있다는 것이다. 따라서 이분탐색으로 N번 순환하면서 값을 찾아야한다.
여기서, K의 값은 주어진다. 따라서 K가 2라면 B[K]보다 같거나 작은 수가 적어도 2개 존재한다는 뜻이다. B[K]를 정확하게 알진 못하지만, 이렇게 순환을 반복하면서
B[K]의 값을 찾아야한다. 다만, B[K]는 안에 있는 녀석들로 구성해야한다. B[K]값을 선정하려면 어떻게 해야할까?
*/
/* 결과
  아쉽게도 내 힘으로 해결하지 못하고, 해답의 힘을 좀 받았다. B[K]를 중간값으로 두고 이리저리 변경하는 것 까지는 좋았는데, 아무래도 비교하는 과정에서 
  시간초과가 발생했다. O(N)으로 생각하면, 10^10은 약 1억 => 1초가 발생한다고 생각했는데, 한번에 해결하는 것이 아닌, 중간값이 계속 변경되기 때문에
  탐색 방법을 잘 변경해야했다. 여기서 해답은 Min(N, B[k]/i)였는데 이를 사용하면 N^2의 탐색이 아닌, N의 탐색으로 획기적으로 단축할 수 있었다.
  다시 보니 이해가 되는게, 최대값 vs 중간값 / i인데 중간값 / i 는 나머지를 없애버리기 때문에 작은것이 반드시 들어있다.
  Min(N, B[K]/i)로 N^2이 아닌, N으로 계산하는게 비법이였다.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
int main()
{
    int N,K,temp,res=0;
    int start,end,middle,output;
    scanf("%d%d",&N,&K);

    start = 1;
    end = K;

    while(1){
      if(start > end) break;
      middle = (start + end)/2;
      temp = 0;
      for(int i=1; i<=N;i++){
        temp += min(N,middle/i);
      }
      if(temp>=K){
        res= middle;
        end = middle-1;
      }
      else{
        start = middle+1;
      }
    }
    printf("%d",res);
    return 0;
    // 시작
}
