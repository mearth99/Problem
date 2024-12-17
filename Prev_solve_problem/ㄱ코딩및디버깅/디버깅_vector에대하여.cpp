#include <vector>
#include <iostream>
using namespace std;


int main(){
	// vector<int>를 디버깅하는데는 애로사항이 핀다.
	/*
	예를 들어, vector<int> arr을 디버깅하려면
	arr을 list로 하여 봐야하고, arr[1] 같이 배열로 접근하려면 오류가 발생한다.

	int arr[10]은 arr[1]로 디버깅하여도 잘뜨니 vector을 포인터화 하여 볼 수 있다.

	int *arrs = &arr[0];
	*/
	vector<int> arr;
	int *arrs = &arr[0];
	/*
	vector<bool>은 사용시 주소가 반환되지 않는 문제가 있어, 이 경우 같은 방식으로 사용할 수 없다.
	그러므로 bool을 사용할 경우 bool이 아닌, bitset을 사용하는 등 다른 방법을 찾아보자.
	*/

	vector<bool> test;
	bool *tests = &test[0];




	return 0;
}