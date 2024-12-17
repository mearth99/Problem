#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

/*
* 문제 설명 및 링크
*/
/*
* 소감
*/

int idx = 0;
string preorder, inorder;
void Go(int start, int end){
	if(start > end) return;
	int mid = inorder.find(preorder[idx++]);
	Go(start,mid-1);
	Go(mid+1,end);
	cout << inorder[mid];
}


int N,M;
void solution() {
	
	cin >> preorder >> inorder;
	Go(0, inorder.size()-1);
}

int main() {
	cout.tie(0);
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	solution();

	return 0;
}

