#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

unsigned int computer_ips[1000];

void PrintIP(unsigned int ip){
  unsigned int bit_mask = (unsigned int)((1<<8) -1) << 24;
  unsigned int temp;
  int order = 3;
  string result="";
  for(int i=0; i<4 ; ++i){
    temp = ip & bit_mask;
    for(int j =order; j>0 ; --j){
      temp = temp >>8;
    }
    result += to_string(temp);
    if(i!=3)
      result += ".";

    bit_mask = bit_mask>>8;
    order--;
  }
  cout<<result<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
    unsigned int network_mask=0;
	cin >> n;
	
	vector<unsigned int> IP_address(n,0);
    for(int i=0;i<n;i++){
		int prev = 0;
		unsigned int ipvalue = 0;
        string binary_value;
		cin >> binary_value;

		for(int j=0;j<binary_value.length();j++){
			if(binary_value[j]=='.'){
				string temp = binary_value.substr(prev,j-prev);
				prev = j+1;
				int value = stoi(temp);
				ipvalue += value;
				ipvalue = (ipvalue << 8);
			}
		}
		string temp = binary_value.substr(prev,binary_value.length()-prev);
		int value = stoi(temp);
		ipvalue += value;
		IP_address[i] = ipvalue;
    }
	for(int i=31;i>=0;i--){
		unsigned int ipvalue = 1 << i;
		bool flag = false;
		for(int j=1;j<n;j++){
			if(((IP_address[0] & ipvalue)) != ((IP_address[j] & ipvalue))){
				flag = true;
				break;
			}
		}
		if(flag) break;
		else network_mask |= ipvalue;
	}
	PrintIP(network_mask&IP_address[0]);
	PrintIP(network_mask);
	return 0;
	
}