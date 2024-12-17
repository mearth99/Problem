
/*
입력
카드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 단, N은 짝수이다.

둘째 줄에 카드의 윗장부터 밑장까지 카드의 값 X (1 ≤ X ≤ 10,000)이 정수로 주어진다.

출력
정훈이가 얻을 수 있는 최대 카드 값의 합을 출력한다
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,value,change=0,sum=0;
  cin >> n;
  vector<int> even;
  vector<int> odd;
  for(int i=1;i<=n;i++){
    cin >> value;
    if(i%2==0)
      even.push_back(value);
    else
      odd.push_back(value);
  }
  value = 0;
  for(int i=0;i<even.size();i++){
    if(value>even[i]-odd[i]){
      value = even[i]-odd[i];
      change = odd[i]-even[i];
    }
    sum+=even[i];
  }
  sum+=change;
  cout << sum;
  return 0;
}