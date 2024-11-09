/*
입력
첫 번째 줄에는 한국에 있는 도시의 수 N(1 ≤ N ≤ 100)과 1인당 내일로 티켓의 가격 R(1 ≤ R ≤ 1,000,000)이 주어집니다. 
두 번째 줄에는 N개의 도시의 이름이 주어집니다. 도시의 이름은 알파벳 대소문자로 구성된 길이 20 이하의 문자열입니다. 
세 번째 줄에는 승현이와 지학이가 여행할 도시의 수 M(1 ≤ M ≤ 200)이 주어집니다. 네 번째 줄에는 승현이와 지학이가 여행할 M개 도시의 이름이 주어집니다. 
이 도시들은 앞서 언급된 N개의 도시 중 하나입니다. 다섯 번째 줄에는 교통수단의 수 K(1 ≤ K ≤ 10,000)가 주어집니다. 마지막 K개의 줄에는 교통수단에 대한 정보가 주어집니다. 
줄마다 교통수단의 종류 Typei, 양 끝 도시 Si, Ei, 1인당 비용 Costi (1 ≤ Costi ≤ 100,000)가 주어집니다. 
Typei는 ‘Subway’, ‘Bus’, ‘Taxi’, ‘Airplane’, ‘KTX’, ‘S-Train’, ‘V-Train’, ‘ITX-Saemaeul’, ‘ITX-Cheongchun’, ‘Mugunghwa’ 중 하나이며, 
모든 도시는 주어진 K개의 교통수단을 이용하여 갈 수 있음이 보장되어 있습니다.

한국에는 이름이 같은 도시가 있을 수 있다. 따라서, N개의 도시의 이름에는 같은 도시의 이름이 두 번 이상 주어질 수도 있다. 이 경우 이러한 도시를 모두 같은 도시라고 생각해야 한다.

출력
한줄에 내일로 티켓을 사는 것이 좋으면 ‘Yes’를 출력하고 그렇지 않으면 ‘No’를 출력합니다. 내일로 티켓을 사더라도 비용이 정확히 같다면 ‘No’를 출력합니다.
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define INF 300000.0

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<string> city_name;
    vector<int> course;
    int n,r,m,k;
    double sum_ticket = 0;
    double sum_nonticket = 0;
    
    cin >> n >> r;
    for(int i=0;i<n;i++){
     string temp_name;
     cin >> temp_name;
     city_name.push_back(temp_name);
    }
    cin >> m;
    sort(city_name.begin(), city_name.end());
    city_name.erase(unique(city_name.begin(),city_name.end()),city_name.end());
    vector<vector<vector<double>>> city(city_name.size(),vector<vector<double>>(city_name.size(),vector<double>(2,INF))); //0은 원래, 1은 할인된
    for(int i=0;i<city_name.size();i++){
      city[i][i][0] = 0;
      city[i][i][1] = 0;
    }
    for(int i=0;i<m;i++){
      string temp_name;
      cin >> temp_name;
      int place = find(city_name.begin(),city_name.end(),temp_name)-city_name.begin();
      course.push_back(place);
    }
    cin >> k;
    for(int i=0;i<k;i++){
      string trans_name,from,to;
      int start,dest;
      double price;
      cin >> trans_name >> from >> to >> price;
      start = find(city_name.begin(),city_name.end(),from)-city_name.begin();
      dest = find(city_name.begin(),city_name.end(),to)-city_name.begin();
      city[start][dest][0] = min(city[start][dest][0],price);
      city[dest][start][0] = min(city[dest][start][0],price);
      if(trans_name.compare("Mugunghwa")==0 || trans_name.compare("ITX-Cheongchun")==0 || trans_name.compare("ITX-Saemaeul")==0){
        city[start][dest][1] = min(city[start][dest][1],(double)0);
        city[dest][start][1] = min(city[dest][start][1],(double)0);
      }
      else if(trans_name.compare("S-Train")==0 || trans_name.compare("V-Train")==0){
        city[start][dest][1] = min(city[start][dest][1],price/2.0);
        city[dest][start][1] = min(city[dest][start][1],price/2.0);
      }else{
        city[start][dest][1] = min(city[start][dest][1],price);
        city[dest][start][1] = min(city[dest][start][1],price);
      }
    }
    for(int k=0;k<city_name.size();k++){
      for(int i=0;i<city_name.size();i++){
        for(int j=0;j<city_name.size();j++){
          city[i][j][0] = min(city[i][j][0],city[i][k][0]+city[k][j][0]);
          city[i][j][1] = min(city[i][j][1],city[i][k][1]+city[k][j][1]);
        }
      }
    }
    for(int i=1;i<course.size();i++){
      int from = course[i-1];
      int to = course[i];
      sum_nonticket += city[from][to][0];
      sum_ticket += city[from][to][1];
    }
    sum_ticket += r;
    sum_nonticket <= sum_ticket ? cout << "No" : cout << "Yes";
    return 0;
}