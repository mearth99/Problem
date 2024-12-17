#include <string>
#include <vector>
#include <queue>
using namespace std;
/*
    연속된 부분 수열이기 때문에, 여러번 계산을 하여 K값을 찾아야한다.
    누적합을 이용하여 탐색한다면 빠르게 계산할 수 있을 것 같다.
    이때 비 내림차순을 이용해보자
    본래라면 N^2에 대해 모든 누적합을 계산해서 K값을 찾아야한다.
    그런데 비내림차순이라면, 
    이전 누적합에 대해 생각할 필요없이 전진만 하면 된다.
*/
struct seq{
    int sum;
    int start;
    int end;
};
struct cmp{
    bool operator()(seq p1, seq p2){
        return p1.sum < p2.sum;
    }
};
vector<pair<int,int>> answer;
int gk;
void lower(vector<int> sum, int start, int end){
    int prev = start-1;
    
    while(start<=end){
        int mid = (start + end)/2;
        if(sum[mid]-sum[prev] == gk) answer.push_back({prev,mid});
        else if(sum[mid]-sum[prev]>gk) end = mid - 1;
        else start = mid +1;
    }
    return;
}
vector<int> solution(vector<int> sequence, int k) {
    int output = 0;
    gk=k;
    vector<int> sum;
    sum.push_back(sequence[0]);
    for(int i=1;i<sequence.size();i++)
        sum.push_back(sequence[i]+sequence[i-1]);
    for(int i=0;i<sum.size()-1;i++){
        lower(sum,i+1,sum.size());  
    }
    return answer;
}