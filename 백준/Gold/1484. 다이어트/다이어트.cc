#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> output;
    int right = 1, left = 1;
    while(true){
        int seq = (right-left) * (right+left);
        if(right - left == 1 && N<seq) break;
        if(seq>N){
            left++;
        }
        else if(seq==N){
            output.push_back(right);
            right++;
        }
        else
            right++;
            
    }
    if(output.empty()) cout << -1;
    else 
        for(auto it: output)
            cout << it << endl;
    return 0;
}