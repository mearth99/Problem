/*
세그먼트트리는 구간합을 빠른 속도로 계산할 수 있는 알고리즘이다.
일반적인 구간합은 SUM을 통해 O(1)에 가깝게 a에서 b까지의 구간합을 계산할 수 있다.
하지만, 이 경우 -> 구간 값이 변동되었을 때 구간값을 해결할 수 없다. (구간 값이 변동하면 n만큼 소모해야하기 때문)

이를 트리형 구조를 통해 log(N)으로 최적화할 수 있다.
*/

#include <iostream>

using namespace std;

#define MAX 100

int arr[MAX];
int tree[MAX*4]; // tree의 크기를 계산하는 법은 보통, log를 취해 높이를 계산한 후 크기를 따지지만, 어림잡아 *4를 하면 최적화는 아니더라도 메모리 오류는 나지 않는다. 

int init(int start, int end, int node){
	//처음 만들어진 arr를 tree로 이동하는 과정이다.
	//길이가 1이 되도록 재귀를 반복하며, 길이가 1인 경우 이에 따라 tree에 arr값이 넣어진다.
	//상위 트리에는 하위 트리의 합이 저장된다. 이를 통해 구간합을 표시한다.
	if(start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start , mid, node*2) + init(mid + 1, end, node*2+1);
}
int sum(int start, int end, int node, int left, int right){
	//left, right : 원하는 구간의 범위
	//start , end : 실제 범위로 잡은 구간 크기

	if(left > end || right < start) return 0; // -> 구간에 일치하는 부분이 하나도 없는 경우 당연하게 0을 반환한다.
	if(left <= start && end<=right) return tree[node]; // -> 원하는 구간이 실제 범위로 잡은 구간보다 큰 경우 모든 값의 합을 반환한다.
	int mid = (start + end) / 2;
	return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right); //재귀로 구간을 탐색하면서 결과를 찾는다.
}

void update_tree(int start, int end, int node, int index, int diff){
	if(index < start || index > end) return; // index가 구간에 없는 경우 더 이상 계산할 필요가 없기 때문에 끝낸다.
	tree[node] += diff; //구간에 있는 경우 변동사항을 적용해야한다.
	if(start == end) return; //결과를 찾았으니 반복할 필요 없이 끝낸다.
	int mid = (start + end) / 2;
	update_tree(start, mid, node*2, index, diff); //재귀를 통해 왼쪽, 오른쪽을 가면서 목적지 트리를 찾아나간다.
	update_tree(mid+1, end, node*2+1, index, diff);
}


int main(){
	for(int i=0;i<=9;i++) arr[i] = i;
	init(0,9,1); //0~9까지 arr를 이용해 tree를 제작한다. 단, tree idx는 무조건 1에서 시작한다. 1에서 시작해야 node*2는 항상짝수, node*2+1는 항상 홀수기 때문..
	cout << sum(0,9,1,2,5); //2번째에서 5번쨰까지 출력하기 값: 10 ||||| 왜? 첫번째: 0 두번째: 1 로 시작하기 떄문.. 1,2,3,4 => 10
	update_tree(0,9,1,2,10);  // 2번째의 값에 10만큼 추가 => 즉, 0, 11, 2, 3 , 4 ..
	return 0;
}