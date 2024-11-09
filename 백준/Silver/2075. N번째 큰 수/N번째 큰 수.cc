#include <bits/stdc++.h>
using namespace std;



void solution(){
	int N;
    cin >> N;
    priority_queue<int,vector<int>, greater<int>> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int temp;
            cin >> temp;

            if(q.size()<N){
                q.push(temp);
            }else{
                q.push(temp);
                q.pop();
            }
        }
    }
    cout << q.top();
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}