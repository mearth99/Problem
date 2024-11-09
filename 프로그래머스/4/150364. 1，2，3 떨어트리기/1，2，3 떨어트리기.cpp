#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> trees[101]; //트리
//next_idx는 first로 실선이 연결되어 있는 자식 idx를 가르키며, second로 자식의 전체 size를 가진다.
vector<pair<int, int>> next_idx(101, { -1,-1 }); // next child tree node idx

vector<int> visit_cnt(101, 0); // 방문 횟수 카운트
//남은 방문 횟수와 현재 방문 횟수, 남은 값을 통해 어떤 값을 넣어야 하는지 알 수 있다.
vector<int> visit_min(101, 0);
int every_cnt = 0;
vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
	for (int i = 0; i < target.size();i++) {
		if (target[i] > 0) {
			every_cnt++;
			visit_min[i+1] = (target[i]+2)/ 3;
		}
	}
	for (auto it : edges) {
		int from = it[0];
		int to = it[1];
		trees[from].push_back(to);
	}
	//초기 설정 세팅
	for (int i = 1; i < 101; i++) {
		if (!trees[i].empty()) {
			sort(trees[i].begin(), trees[i].end());
			next_idx[i] = { trees[i][0],0 };
		}
	}
	//target을 모두 충족시킬 때까지 loop를 돌린다.
	int every_cnt_backup = every_cnt;
	while (every_cnt != 0) {
		int idx = 1; // root node에서 시작한다. root node는 1
		while(!trees[idx].empty()) { // leaf node까지 반복한다. 
			int nt = next_idx[idx].first; // node[idx]에서 실선으로 연결된 자식의 값이다.
			next_idx[idx].second++; // node[idx]에서 실선으로 연결된 자식을 찾는 idx이다.
			if (next_idx[idx].second == trees[idx].size()) //한바퀴 돌았으면 맨 처음으로 돌아와야한다.
				next_idx[idx].second = 0;
			next_idx[idx].first = trees[idx][next_idx[idx].second];
			//이 과정을 통해 다음에 갈 nt를 얻었다. 이 nt는 다음 자식으로 trees[nt]로 사용하면 된다.
			idx = nt;
		}
		//while를 탈출했다는 것은 지금 idx가 leaf node라는 것이다.
		visit_cnt[idx]++;
		visit_min[idx]--;
		if (visit_min[idx] == 0) every_cnt--;
	}

	for (int i = 1; i < 101; i++) {
		if (!trees[i].empty()) {
			next_idx[i] = { trees[i][0],0 };
		}
	}
	every_cnt = every_cnt_backup;
	while (every_cnt != 0) {
		int idx = 1; // root node에서 시작한다. root node는 1
		while (!trees[idx].empty()) { // leaf node까지 반복한다. 
			int nt = next_idx[idx].first; // node[idx]에서 실선으로 연결된 자식의 값이다.
			next_idx[idx].second++; // node[idx]에서 실선으로 연결된 자식을 찾는 idx이다.
			if (next_idx[idx].second == trees[idx].size()) //한바퀴 돌았으면 맨 처음으로 돌아와야한다.
				next_idx[idx].second = 0;
			next_idx[idx].first = trees[idx][next_idx[idx].second];
			//이 과정을 통해 다음에 갈 nt를 얻었다. 이 nt는 다음 자식으로 trees[nt]로 사용하면 된다.
			idx = nt;
		}
		//while를 탈출했다는 것은 지금 idx가 leaf node라는 것이다.
		int visited = visit_cnt[idx]--;
        if (target[idx - 1] == 0) {
			vector<int> excep(1, -1);
			return excep;
		}
		if ((visited - 1) * 3 >= target[idx - 1]) {
			answer.push_back(1);
			target[idx - 1]--;
		}
		else {
            
			answer.push_back(target[idx - 1] - (visited - 1) * 3);
			target[idx - 1] -= (target[idx - 1])-(visited - 1) * 3;
		}
		if (visit_cnt[idx] == 0) every_cnt--;
	}
	// 이 시점에서 각 leaf node에 대한 방문 횟수를 알게 되었다. 이제 이 방문 횟수에 따라 적절하게 answer를 지정하면 된다.
	//(방문횟수-1)*3 >= 남은 값 이라면, 1을 반환한다.
	//(방문횟수-1)*3 < 남은 값 이라면 남은값 - (방문횟수 -1) *3을 반환한다.
	

    return answer;
}