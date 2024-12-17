#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
struct customs{
	int number,time,end;
};
struct cmp{
	bool operator()(pair<int,int> p1, pair<int,int> p2){
		if(p1.first==p2.first) return p1.second > p2.second;
		return p1.first > p2.first;
	}
};
vector<int> outputs;
int N,M,K,A,B;
vector<int> A_list;
vector<int> B_list;
vector<int> end_list;
vector<customs> order_time;
vector<customs> repair_time;
queue<int> visit; 
priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> order; // 고객번호 
priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> repair; //시간, 고객번호
int cur_time = 0;
int custom_idx = 1;
bool Set_visit(){
	if(visit.empty()) return false;
	if(visit.front()<=cur_time){
		order.push({visit.front(),custom_idx++});
		visit.pop();
		return true;
	}
	return false;
}
void Set_order(){
	for(int i=0;i<N;i++){
		if(order_time[i].end==cur_time){
			repair.push({cur_time,order_time[i].number});
			order_time[i].number = -1;
			order_time[i].end = -1;
		}
		if(order_time[i].number == -1){
			if(order.empty()) continue;
			order_time[i].number = order.top().second;
			order_time[i].end = cur_time + order_time[i].time;
			order.pop();
			if(i==A) A_list.push_back(order_time[i].number);
		}
	}
	return;
}
void Set_repair(){
	for(int i=0;i<M;i++){
		if(repair_time[i].end==cur_time){
			repair_time[i].number = -1;
			repair_time[i].end = -1;
		}
		if(repair_time[i].number==-1){
			if(repair.empty()) continue;
			repair_time[i].number = repair.top().second;
			repair_time[i].end = cur_time + repair_time[i].time;
			repair.pop();
			end_list.push_back(repair_time[i].number);
			if(i==B) B_list.push_back(repair_time[i].number);
		}
	}

}
int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		cur_time = 0;
		custom_idx = 1;
		cin >> N >> M >> K >> A >> B;
		A-=1;
		B-=1;
		for(int i=0;i<N;i++){
			int temp;
			cin >> temp;
			order_time.push_back({-1,temp,-1});
		}
		for(int i=0;i<M;i++){
			int temp;
			cin >> temp;
			repair_time.push_back({-1,temp,-1});
		}
		for(int i=0;i<K;i++){
			int temp;
			cin >> temp;
			visit.push(temp);
		}
		while((end_list.size()!=K)){
			while(Set_visit());
			Set_order();
			Set_repair();
			cur_time++;
		}
		int sum = 0;
		for(auto it: A_list){
			for(auto i: B_list){
				if(it==i) sum+=it;
			}
		}
		if(sum==0) outputs.push_back(-1);
		else outputs.push_back(sum);
		A_list.clear();
		B_list.clear();
		order_time.clear();
		repair_time.clear();
		end_list.clear();
		while(!visit.empty())
			visit.pop();
		while(!order.empty())
			order.pop();
		while(!repair.empty())
			repair.pop();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}