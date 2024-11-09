#include <bits/stdc++.h>
using namespace std;

int N;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}


int get_space(vector<pair<int,int>> space){
    int maxidx = max_element(space.begin(),space.end())-space.begin();
    int s = 0;
    for(int i=0;i<maxidx;i++){
        s += (space[i+1].second - space[i].second)*space[i].first;
    }
    s+= space[maxidx].first * 1;
    for(int i=space.size()-1;i>maxidx;i--){
        s += (space[i].second - space[i-1].second)*space[i].first;
    }
    return s;
}

int main(){
    cin >> N;
    vector<pair<int,int>> arr(N); //높이, 위치
    vector<pair<int,int>> choice;
    for(int i=0;i<N;i++){
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<N;i++){
        pair<int,int> left_max = *max_element(arr.begin(),arr.begin()+i);
        pair<int,int> right_max = *max_element(arr.begin()+i,arr.end());
        if(arr[i].first < left_max.first && arr[i].first < right_max.first) continue;
        choice.push_back(arr[i]);
    }
    cout << get_space(choice);
    return 0;
}