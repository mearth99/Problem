#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
/*
l과 r을 0에서 부터 증가시킨다.
r-l은 현재 대상자의 계단 길이가 된다.
히스토그램 값이 r-l보다 큰지 확인한다.
크다면 ,같다면, r을 증가시킨다.
작다면, l을 증가시킨다.
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,l=0,r=0,output=0;
    cin >> N;
    vector<int> arr(N);
    for(int i=0;i<N;i++)
        cin >> arr[i];
    while(l<N && r <N){
        int v = r-l+1;
        if(arr[r]>=v){
            r++;
            output = max(v,output);
        }else{
            l++;
        }
    }
    cout << output;
}