#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> q;

int main(){
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        q.push(temp);
    }
    int sum = 0;
    while(q.size()>1){
        int first = q.top(); q.pop();
        int second = q.top(); q.pop();
        sum += first + second;
        q.push(first+second);
    }
    cout << sum;
    return 0;
}