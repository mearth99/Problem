
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(string &a, string &b){
    return a+b > b+a;
}

int main(){
    int N;
    cin >> N;
    vector<string> arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(),cmp);
    if(arr[0]=="0") cout << 0;
    else{
        string output = "";
        for(auto it : arr){
            output += it;
        }
        cout << output;
    }
}