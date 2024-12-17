
/*
입력
첫 줄에 연병장의 크기 N과 조교의 수 M이 주어진다.
둘째 줄에 연병장 각 칸의 높이 Hi가 순서대로 N개 주어진다.
셋째 줄부터 M개의 줄에 각 조교의 지시가 주어진다.
각 조교의 지시는 세 개의 정수 a, b, k로 이루어져 있다.
k ≥ 0인 경우 a번 칸부터 b번 칸까지 높이가 각각 |k| 만큼 늘어나도록 흙을 덮어야 한다.
k < 0인 경우 a번 칸부터 b번 칸까지 높이가 각각 |k| 만큼 줄어들도록 흙을 파내야 한다.
출력
모든 지시를 수행한 뒤 연병장 각 칸의 높이를 공백을 사이에 두고 출력한다.
*/
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,m;
  int x1,x2,v;
  cin >> n >> m;
  vector<int> A(n+1);
  vector<int> Sum(n+1);
  for(int i=0;i<n;i++)
    cin >> A[i];
  while(m>0){
    cin >> x1 >> x2 >> v;
    Sum[x1-1] += v;
    Sum[x2] += v*-1;
    m--;
  }
  for(int i=1;i<=n;i++)
      Sum[i] += Sum[i-1];
  for(int i=0;i<n-1;i++){
      cout << A[i]+Sum[i] << " ";
    }
    cout << A[n-1]+Sum[n-1] << endl;
  return 0;
}