//A[1], A[2], ..., A[N]의 N개의 정수가 저장되어 있는 배열이 있다. 이 배열 A의 부분합이란 1 ≤ i ≤ j ≤ N인 정수 i와 j에 대해 A[i]부터 A[j]까지의 합을 말한다.
//N과 A[1], A[2], ..., A[N]이 주어졌을 때, 이러한 N×(N+1)/2개의 부분합 중 합이 K인 것이 몇 개나 있는지를 구하는 프로그램을 작성하시오.
/*
2차원 배열이 주어졌을 때 (i, j) 위치부터 (x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 프로그램을 작성하시오. 배열의 (i, j) 위치는 i행 j열을 나타낸다.

첫째 줄에 배열의 크기 N, M(1 ≤ N, M ≤ 300)이 주어진다. 다음 N개의 줄에는 M개의 정수로 배열이 주어진다. 
배열에 포함되어 있는 수는 절댓값이 10,000보다 작거나 같은 정수이다. 그 다음 줄에는 합을 구할 부분의 개수 
K(1 ≤ K ≤ 10,000)가 주어진다. 다음 K개의 줄에는 네 개의 정수로 i, j, x, y가 주어진다(1 ≤ i ≤ x ≤ N, 1 ≤ j ≤ y ≤ M).

K개의 줄에 순서대로 배열의 합을 출력한다. 배열의 합은 2^31-1보다 작거나 같다.
*/
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main()
{
  int n,m,k;
  cin >> n >> m;
  vector<vector<int>> sum(n+1, vector<int> (m+1));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> sum[i][j];
      sum[i][j] += sum[i][j-1];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      sum[i][j] += sum[i-1][j];
    }
  }
  cin >> k;
  for(int i=0;i<k;i++){
    int x1,x2,y1,y2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << sum[y2][x2]-sum[y1-1][x2]-sum[y2][x1-1]+sum[y1-1][x1-1]<<endl;
  }
  return 0;
}