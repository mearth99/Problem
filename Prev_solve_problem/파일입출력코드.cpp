#include <bits/stdc++.h>
using namespace std;

ofstream file("output.txt");
void outfile(char arr[10001][501]){
	if(file.is_open()){
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				file <<  arr[i][j] << ' ' ;
			file << endl;
		}
	}else{
		cout << "파일 에러.";
		return;
	}
	file.clear();
}
