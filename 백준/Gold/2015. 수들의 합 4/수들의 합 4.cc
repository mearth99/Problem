//A[1], A[2], ..., A[N]의 N개의 정수가 저장되어 있는 배열이 있다. 이 배열 A의 부분합이란 1 ≤ i ≤ j ≤ N인 정수 i와 j에 대해 A[i]부터 A[j]까지의 합을 말한다.
//N과 A[1], A[2], ..., A[N]이 주어졌을 때, 이러한 N×(N+1)/2개의 부분합 중 합이 K인 것이 몇 개나 있는지를 구하는 프로그램을 작성하시오.
/*
첫째 줄에 정수 N과 K가 주어진다. (1 ≤ N ≤ 200,000, |K| ≤ 2,000,000,000) N과 K 사이에는 빈칸이 하나 있다. 
둘째 줄에는 배열 A를 이루는 N개의 정수가 빈 칸을 사이에 두고 A[1], A[2], ..., A[N]의 순서로 주어진다. 주어지는 정수의 절댓값은 10,000을 넘지 않는다.
첫째 줄에 합이 K인 부분합의 개수를 출력한다.
*/
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main()
{
  int n,m;
  cin >> n >> m;
  vector<long long> sum(n+1);
  map<long long, long long> count; //key data
  long long answer=0;
  for(int i=1;i<=n;i++){
    cin >> sum[i];
    sum[i] += sum[i-1];
    if(sum[i]==m) answer++;
  }
  for(int i=1;i<=n;i++){
    answer += count[sum[i]-m];
    count[sum[i]]++;
  }
  cout << answer;
  return 0;
}