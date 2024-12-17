#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
map<string, int> friend_name;
vector<int> friend_gift;
vector<int> gift_level;
vector<vector<int>> arr;

int solution(vector<string> friends, vector<string> gifts) {
    int N = friends.size();
    arr.resize(N, vector<int>(N));
    friend_gift.resize(N);
    gift_level.resize(N);
    for(int i=0;i<N;i++)
        friend_name.insert({friends[i],i});
    for(auto it : gifts){
        string left,right;
        left = it.substr(0,it.find(' '));
		right = it.substr(it.find(' ')+1, it.size()-left.size());
		arr[friend_name[left]][friend_name[right]]++; // left가 right에게 선물을 주었다.
		gift_level[friend_name[left]]++;
		gift_level[friend_name[right]]--;
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i][j]==arr[j][i]){
				//선물지수를 확인해야한다
				if(gift_level[i]==gift_level[j]) continue;
				else if(gift_level[i] > gift_level[j]) friend_gift[i]++;
				else friend_gift[j]++;
			}else if(arr[i][j] > arr[j][i]){ //i가  j에게 선물을 더 줬다면 
				//i는 j에게 선물을 더 받아야한다.
				friend_gift[i]++;
			}else{
				//j는 i에게 선물을 더 받아야한다.
				friend_gift[j]++;
			}
		}
    }
	int maxv = *max_element(friend_gift.begin(),friend_gift.end());
    return maxv;
}


int main(){
	vector<string> f = {"joy", "brad", "alessandro", "conan", "david"};
	vector<string> d = {"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"};
	solution(f,d);
	return 0;
}