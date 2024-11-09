#include <bits/stdc++.h>
using namespace std;




void solution(){
	int N;
	int all[500001] = {0};
	int arr[8001] = {0};
	int sum = 0;
	cin >> N;
	for(int i=0;i<N;i++){
		int input;
		cin >> input;
		sum += input;
		all[i] = input;
		arr[input+4000]++;
	}
	//1.
	cout << round((double)sum/N) + 0.0 << '\n';
	//2.
	sort(all, all+N);
	cout << all[(N-1)/2] << '\n';
	//3.
	int manyv = *max_element(arr,arr+8001);
	int target = 0, cnt = 0;
	for(int i=0;i<8001;i++)
		if(arr[i]==manyv){
			cnt++;
			target = i;
			if(cnt==2)
				cout << i-4000 << '\n'; 
		}
	if(cnt==1) cout << target-4000 << '\n';
	//4.
	cout << all[N-1] - all[0];
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}