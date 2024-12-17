//9095 1,2,3, 더하기

/* 문제
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
*/
 /* 입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.
 */

 /* 출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
 */

/* 예상
n을 1과 2와 3의 합으로 나타내는 모든 경우의 수를 출력하는 문제다(순서있음)
먼저, 모든 수는 1의 합으로 나타낼 수 있으니 dp[1] = 1이다.
그 다음 짝수는 2의합으로 나타낼 수 있으니 1에 1과 2의 합을 더하면 된다.
dp[2]는 2를 pow해서 나온 2의 수를 구한다. 즉 4라면 pow는 2개가 되는데
이 값에서 2-1(2의 갯수) 4-2(1의 갯수)를 하여 나온 값 3C2로 값을 구하면 된다.
dp[3]은 1과 2에 대해서 같은 방법을 반복하여 구하면 된다.
*/
/* 결과

*/
#include <iostream>
#include<cmath>
#include<map>
#include<string>
using namespace std;
map<string,int> a;
int arr[3] = {1,2,3};
void Sol(string s, int n, int cur){
    for(int i=0;i<3;i++){
        cur += arr[i];
        if(cur>n) continue;
        else if(cur==n) a[s+to_string(arr[i])]++;
        else Sol(s+to_string(arr[i])+"+",n,cur);
        cur -= arr[i];
    }
    return;
}
int main()
{
    int n,k,count=0;
    cin >> n >> k;
    Sol("",n,0);
    if(a.size()<k) cout << -1;
    else
        for(auto it: a){
            count++;
            if(count==k) cout << it.first;
        }
    return 0;   
}
