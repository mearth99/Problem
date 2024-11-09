/*
입력
첫째 줄에 점수 N이 정수로 주어진다. (10 ≤ N ≤ 99,999,999) 단, 점수 N의 자릿수는 항상 짝수 형태로만 주어진다.

출력
첫째 줄에 럭키 스트레이트를 사용할 수 있다면 "LUCKY"를, 사용할 수 없다면 "READY"라는 단어를 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int StoI(string target){
  int sum=0;
  for(int i=0;i<target.length();i++)
    sum += target.at(i) - '0';
  return sum;
}

int main(){
  string N,first,second;
  cin >> N;
  first = N.substr(0,N.size()/2);
  second = N.substr(N.size()/2,N.length());
  int first_sum = StoI(first);
  int second_sum = StoI(second);
  if(first_sum==second_sum) cout << "LUCKY";
  else cout << "READY";

}
