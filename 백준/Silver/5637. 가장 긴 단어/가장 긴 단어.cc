#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<iostream>
#include<queue>

using namespace std;

int main() {

	string result = "";
	int rs = 0;
	int ns = 0;
	string name;
	while (cin >> name) {
		if (name == "E-N-D") break;
		int ns = 0;
		for (auto it : name) {
			if (it >= 'A' && it <= 'Z' || it >= 'a' && it <= 'z' || it == '-')
				ns++;
		}
		if (ns > rs) {
			rs = ns;
			result = name;
		}
	}
	for (size_t i = 0; i < result.length(); i++) {
		// 대문자인 경우에만 변환 ('A'~'Z' 범위 확인)
		if (result[i] >= 'A' && result[i] <= 'Z') {
			result[i] = result[i] + 32;
		}
		if (!(result[i] >= 'A' && result[i] <= 'Z' || result[i] >= 'a' && result[i] <= 'z' || result[i]=='-')) continue;
		cout << result[i];
	}
	return 0;
}