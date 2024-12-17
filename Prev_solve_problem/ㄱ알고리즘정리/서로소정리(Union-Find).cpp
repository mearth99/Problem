/*
 서로소 정리란, 서로간에 분리되어 있는 집합을 구분할 때 사용한다.
 예를 들어, 그래프가 모두 연결되어 있지 않고, 연결된 집합만을 구할 때
 또는 사이클이 있는지 파악하는데 사용할 수 있다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 500
int node[MAX];
int GetParent(int x){
  if(x==node[x]) return x;
  else node[x] = GetParent(node[x]);
}
void UnionParent(int a, int b){
  a = GetParent(a);
  b = GetParent(b);
  if(a<b) node[b] = a;
  else node[a] = b; 
}
bool FindParent(int a, int b){
  a = GetParent(a);
  b = GetParent(b);
  if(a==b) return true;
  else return false;
}
int main(){
  for(int i=0;i<MAX;i++)
    node[i] = i;
  //만약 FindParent의 결과가 True, Node a와 B가 서로 연결되어있다. Cycle가 있다.
  //이를 통해 크루스칼 알고리즘을 활용할 수 있다.
  return 0;
}