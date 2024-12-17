#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
/*
  1. 장르별로 가장 많이 재생된 노래 2개씩 모아 Best Album을 출시하려고 한다.
  노래는 고유 번호로 구분하며, 노래 수록 기준은 다음과 같다.
  2. 속한 노래가 많이 재생된 장르를 먼저 수록한다.
  3. 장르 내에서 많이 재생된 노래를 먼저 수록한다.
  4. 장르 내에서 재생횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록한다.
*/
/*
  순서: 1. 탐색하면서 장르의 재생 횟수 순서로 정렬한다.
  2. 장르 별로 구분했다면, 장르 내부에서도 정렬한다.
  -> 내부 정렬시 재생횟수가 같다면, 먼저 있던 노래가 승리. ( 고유번호가 낮은 노래 )
  3. 순서대로 2개씩 리턴하여 최종 리턴 시킨다( 노래가 1개라면 1개만 리턴 )
*/

/*
 c++에 기능이 많지만, 아직 미숙하여 for 3중으로 해결하였다.
 해쉬 문젠대 해쉬 문제로 다시 도전해야지.
*/
using namespace std;

struct music{
  string genres;
  vector<int> plays;
  vector<int> unique;
  int sum;
};
  music musics[100];

bool compare(const music& p1, const music& p2){
  return p1.sum > p2.sum;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    int music_size = 1;

    vector<int> answer;
    for(int i=0;i<genres.size();i++){
      int flag = 0;
      int insertflag = 0;
      for(int j=0;j<music_size;j++){
        if(genres[i].compare(musics[j].genres)==0){
          //장르가 동일하면 하위로 포함되어야 한다. + 추가탐색할 필요가 없다. sum은 증가시키고, plays에 따라 unique 위치를 조정해야한다.
          flag = 1;
          musics[j].sum += plays[i];
          for(int k=0;k<musics[j].plays.size();k++){
            if(plays[i] > musics[j].plays[k]){
              insertflag=1;
              //insert를 k지점에 삽입하면 된다.
              musics[j].plays.insert(musics[j].plays.begin()+k,plays[i]);
              musics[j].unique.insert(musics[j].unique.begin()+k,i);
              break;
            }else if(plays[i] == musics[j].plays[k]){
              insertflag=1;
              //고유번호를 비교해야하는데, 당연히 후입이 고유번호가 낮기 때문에 따로 비교하지 않고 바로 삽입하도록 하겠다.
              musics[j].plays.insert(musics[j].plays.begin()+k+1,plays[i]);
              musics[j].unique.insert(musics[j].unique.begin()+k+1,i);
              break;
            }
          }
          //제일 마지막에 추가한다.
          if(insertflag==0){
            musics[j].plays.push_back(plays[i]);
            musics[j].unique.push_back(i);
            break;
          }
        }
      }
      //모든 장르를 탐색했는데 겹치지 않는다면 추가로 장르를 추가해야한다 -> 장르를 추가하며 초기화해야한다.
      if(flag==0){
        musics[music_size].genres = genres[i];
        musics[music_size].plays.push_back(plays[i]);
        musics[music_size].sum = plays[i];
        musics[music_size].unique.push_back(i);
        music_size++;
      }
      
    }
    //장르의 sum 순서대로 정렬해야한다.
    sort(musics,musics+music_size,compare);
    for(int i=0;i<music_size;i++){
        cout << musics[i].genres << " ";
        for(int j=0;j<musics[i].unique.size();j++){
            cout << musics[i].unique[j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<music_size;i++){
        for(int j=0,max_size = 0;j<musics[i].unique.size()&&max_size<2;j++,max_size++){
            answer.push_back(musics[i].unique[j]);
        }
    }
    return answer;
}