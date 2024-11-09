#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int check(string s, bool flag){
    int left=0, right= s.length()-1;    
    while(left<right){
        if(s.at(left)==s.at(right)){
            left++;
            right--;
        }else if(flag==0){
            int l = check(s.substr(left+1,right-left),true);
            int r = check(s.substr(left,right-left),true);
            if(l==0 || r==0) return 1;
            else return 2;
        }
        else{
            return 2;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> output;
    for(int i=0;i<N;i++){
        string tar;
        cin >> tar;
        output.push_back(check(tar,0));
    }
    for(auto it: output)
        cout << it << endl;
}