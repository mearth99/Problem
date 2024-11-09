#include <iostream>
#include <string>
#include <vector> 
using namespace std;

int main() {

	int N;
	cin >> N;
	int one, two;
	vector<string> arr(N);
	for (int i = 0; i < N;i++) {
		cin >> arr[i];
		if (arr[i] == "KBS1")
			one = i;
		else if (arr[i] == "KBS2")
			two = i;
	}
	if(one > two) two++;
	for (int i = 0; i < one; i++) cout << '1';
	for (int i = 0; i < one; i++) cout << '4';
	if (two != 1) {
		for (int i = 0; i < two; i++) cout << '1';
		for (int i = 1; i < two; i++) cout << '4';
	}
	return 0;
}