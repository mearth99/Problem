#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct datas{
    int prices;
    int times;
    int unique;
};

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int lists[100001];
    fill_n(lists,100001,-1);
    //가격이 떨어지다 -> 다음 배열에 자기 자신보다 낮은게 몇개 있는가? => 메모리를 통해 만들 수 있을 듯?
    //2중 for문으로 해결할 수 있을까?
    vector<datas> stacks; //가격, 시간, 고유번호
    int times=1;
    for(int i=0;i<prices.size();i++){
        if(!stacks.empty()){
            //가격이 떨어진 친구들은 더 이상 신경쓸 필요가 없으니, 등록하고 제거한다.   
            while(prices[i]<stacks[stacks.size()-1].prices && !stacks.empty()){
                lists[stacks[stacks.size()-1].unique] = times - stacks[stacks.size()-1].times;
                stacks.pop_back();
            }
        }
            datas temp;
            temp.prices = prices[i];
            temp.times = times++;
            temp.unique = i;
            stacks.push_back(temp);
        
    }
    int stacksize = stacks.size();
    for(int i=0;i<stacksize;i++){
        cout << stacks[stacks.size()-1].times << endl;
        lists[stacks[stacks.size()-1].unique] = times - stacks[stacks.size()-1].times-1;
        stacks.pop_back();
    }
    for(int i=0;i<100001;i++){
        if(lists[i]==-1)
            continue;
        else
            answer.push_back(lists[i]);
    }
    return answer;
    
}