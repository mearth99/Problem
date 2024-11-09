#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<vector>

using namespace std;


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,left=0,right=0,distance=2000000001;
    vector<int> T;
    vector<int> output(2);
    cin >> N;
    T.resize(N);
    right=N-1;
    for(int i=0;i<N;i++){
        cin >> T[i];
    }
    while(left<right){
        int Tleft = T[left];
        int Tright = T[right];
        if(Tleft+Tright>0){
            if(distance>Tleft+Tright){
                distance = Tleft+Tright;
                output = {Tleft,Tright};
            }
            right--;
        }else if(Tleft+Tright==0){
            output = {Tleft,Tright};
            break;
        }
        else{
            if(distance>(Tleft+Tright)*-1){
                distance = (Tleft+Tright)*-1;
                output = {Tleft,Tright};
            }
            left++;
        }
    }
    cout << output[0] << " " << output[1];
}