#include <string>
#include <vector>

using namespace std;

int setsecond(int h, int m, int s){
	return h*3600 + m*60 + s;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
	int start_time = setsecond(h1,m1,s1);
	int end_time = setsecond(h2,m2,s2);
	double hour_bar = (start_time / 120)%360;
	double minute_bar = ((start_time-h1*3600) / 10)%360;
	double second_bar = (((start_time-h1*3600-m1*60)) * 6)%360;
	return 0;
}

int main(){
	solution(1,5,5,1,5,6);
	return 0;
}