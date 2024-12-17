#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int curhealth = health;
	int repeat_cnt = 0;
	int maxtime = attacks.back()[0];
	int a_cnt=0;
	for(int t=0;t<=maxtime;t++){
		if(t==attacks[a_cnt][0]){
			repeat_cnt = 0;
			curhealth -= attacks[a_cnt++][1];
			if(curhealth<=0) return -1;
		}
		else{
			curhealth += bandage[1];
			if(++repeat_cnt==bandage[0]){
				curhealth += bandage[2];
				repeat_cnt = 0;
			}
			if(curhealth>health) curhealth = health;
		}
	}
	
	int answer = curhealth;
    return answer;
}