//16395 파스칼의 삼각형

/* 문제
파스칼의 삼각형은 이항계수를 삼각형 형태로 배열한 것인데, 블레즈 파스칼(1623-1662)을 따라 이름 붙여졌다.

단순한 형태로, 파스칼의 삼각형은 다음과 같은 방법으로 만들 수 있다.

N번째 행에는 N개의 수가 있다.
첫 번째 행은 1이다.
두 번째 행부터, 각 행의 양 끝의 값은 1이고, 나머지 수의 값은 바로 위 행의 인접한 두 수의 합이다.
예를 들어, n=3이면 3번째 행의 2번째 수는 위 행의 인접한 두 수 (1과 1)을 더해서 만든다. 

n=6일 때, 파스칼 삼각형의 6번째 행의 10은 5번째 행의 인접한 두 수(4와 6)을 더해서 구한다. 
*/
 /* 입력
첫째 줄에 정수 n과 k가 빈칸을 사이에 두고 차례로 주어진다. 이 때, 1 ≤ k ≤ n ≤ 30을 만족한다.
 */

 /* 출력
첫째 줄에 n번째 행에 있는 k번째 수를 출력한다.
 */

/* 예상
파스칼의 삼각형은 n, n-1, n-2... 1까지 길이가 줄어든다. 각 줄의 맨처음과 맨 마지막은 1이다.
처음과 끝이라면 값: 1이다.
처음과 끝이 아니라면: [h-1][n-1] + [h][n-1]의 값이 된다.

*/
/* 결과
easy. 무난한 파스칼의 정의로 만든 동적계획법..이라보기엔 누적합같기도? 딱히 동적계획법같지는 않은데..
*/
#include <iostream>

using namespace std;

int dp[31][31];

int main()
{
    fill(&dp[0][0],&dp[31][31],1);
    int n,k;
    cin >> n >> k;
    for(int i=2;i<30;i++){
        for(int j=1;j<i;j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
        }
    }
    cout << dp[n-1][k-1];
}
