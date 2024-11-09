#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> team;
pair<int,int> dfs(vector<int> &sales, int member) {
    if(team.find(member) == team.end())
    	return {0, sales[member-1]};
    else {
        int sum = 0, min_diff = 1e9;
        bool flag = false;
        for(auto mem: team[member]) {
            auto res = dfs(sales, mem);
            sum += min(res.first, res.second); 
            if(res.first >= res.second) flag = true;
            min_diff = min(min_diff, res.second - res.first);
        }
        if(flag) return {sum, sales[member-1] + sum};
        else return {sum + min_diff, sales[member-1] + sum};
    }    
}

int solution(vector<int> sales, vector<vector<int>> links) {
    for(auto link: links) {
        team[link[0]].push_back(link[1]);
    }
    auto res = dfs(sales, 1);    
    return min(res.first, res.second);
}