#include <bits/stdc++.h>
using namespace std;

vector<string> output;
void solution(){
	int N, K;
	cin >> N >> K;
	int stopcnt=0;
	int t_15 = 15*60;
	int t_18 = 18*60;
	int t_21 = 21*60;
	
	for(int i=0;i<N-1;i++){
		int b_15 = 0;
		int b_18 = 0;
		int b_21 = 0;
		for(int j=0;j<60*24;j+=60){
			if(j>=t_15 && !b_15){
				b_15 = 1;
			}
			if(j>=t_18 && !b_18){
				b_18 = 1;
			}
			if(j>=t_21 && !b_21){
				b_21 = 1;
				t_15 += K;
				if(t_15>=60*24){
					t_15 -= 60*24;
				}
				t_18 += K;
				if(t_18>=60*24){
					t_18 -= 60*24;
				}
				t_21 += K;
				if(t_21>=60*24){
					t_21 -= 60*24;
				}
			}
		}
	}
	int b_15 = 0;
	int b_18 = 0;
	int b_21 = 0;
	for(int j=0;j<60*24;j+=60){
			if(j>=t_15 && !b_15){
				b_15 = 1;
				output.push_back(to_string(t_15/60) + ':' + to_string(t_15%60));
			}
			if(j>=t_18 && !b_18){
				b_18 = 1;
				output.push_back(to_string(t_18/60) + ':' + to_string(t_18%60));
			}
			if(j>=t_21 && !b_21){
				b_21 = 1;
				output.push_back(to_string(t_21/60) + ':' + to_string(t_21%60));
				t_15 += K;
				if(t_15>=60*24){
					t_15 -= 60*24;
				}
				t_18 += K;
				if(t_18>=60*24){
					t_18 -= 60*24;
				}
				t_21 += K;
				if(t_21>=60*24){
					t_21 -= 60*24;
				}
			}
		}
	cout << output.size() << endl;
	for(auto it: output){
		cout << it << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	// file.clear();
    return 0;
}

