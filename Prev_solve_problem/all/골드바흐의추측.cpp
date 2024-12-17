#include <bits/stdc++.h>
using namespace std;

// 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
// 백만 이하의 모든 짝수에 대해서 이 추측을 검증하는 프로그램을 작성하시오.
// 시간: 0.5초 
//

#define Maxv 1000001 

bool Prime[Maxv] = {false};

void Go_Strainer(){
	
	Prime[0] = Prime[1] = true;

	for(int i=2;i*i<Maxv;i++){
		if(Prime[i]==true) continue;
		for(int j=i*i;j<=Maxv;j+=i){
			Prime[j] = true;
		}
	}
}

int main(){
	Go_Strainer();
	int n = 0;
	while(1){
		bool flag = false;
		cin >> n;
		if(n==0) break;
		for(int i=3;i<n;i+=2){
			if(!Prime[n-i] && !Prime[i]){
				flag = true;
				cout << n << " = " << i << " + " << n-i << '\n';
				break;
			}
		}
		if(!flag) cout << "Goldbach's conjecture is wrong";

	}

    return 0;
}