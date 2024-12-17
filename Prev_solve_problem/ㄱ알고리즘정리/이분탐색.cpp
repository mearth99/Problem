/*
 이분탐색은 탐색범위를 1/2로 좁혀가며 탐색을 하는 것이다.
 이분 탐색의 경우 범위를 좁혀가며 조건을 만족하는지 알 수 있기 때문에, 탐색범위가 많은 경우 좋다.
 즉, 탐색 범위가 2000만을 넘어간다면 이진탐색으로 접근하기 좋다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int graph[500];
void binary_scan(int goal){
  int start, mid, end;
  while(start<=end){
    //start가 end보다 같거나 작은 경우로 해야하는 이유는 모든 범위를 탐색하기 위함이다. 결국 mid가 start와 같아지는 경우 start == end가 될 수 있기 때문에
    //이렇게 설정해야 모든 범위를 탐색할 수 있다.
    int count=0;
    mid = (start + end ) / 2;
    for(int i=0; i<500; i++){
      if(mid<graph[i])
        count++;
    }
    if(count > goal){
      //만약에 목표가 더 많아서 왼쪽을 탐색해야할 경우 end를 줄인다.
      end = mid -1;
    }else{
      //만약에 목표가 더 적어서 오른쪽을 탐색해야할 경우 start를 늘린다.
      start = mid +1;
    }
  }
}

int main(){
  binary_scan(1);
  return 0;
}