#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

#define MAX 4000000

int N, sum;
int check[MAX+1]; // 0을 소수로 표기  
vector<int> p_sum;
vector<int> prime_num;


int main()
{
	cin >> N;
	p_sum.push_back(0);
	// 에라토스테네스의 체 	 	
	for(int i = 2; i < sqrt(MAX); i++)
	{
		for(int j = 2*i; j <= MAX; j += i)
			check[j] = 1; // 소수가 아님을 표시  
	}
	 	
	for(int i = 2; i <= MAX; i++) 
	{
		if(check[i] == 0) 
		{
			sum += i;
			p_sum.push_back(sum);
		}
	}
	
	// 투포인터 
	int ans, left, right;
	ans = 0;
	left = 0;
	right = 0;	
	
	while(left <= right && right < p_sum.size())
	{
		if(p_sum[right] - p_sum[left] > N)
		{
			left++;
		}
		else if(p_sum[right] - p_sum[left] < N)
		{
			right++;
		}
		else // (p_sum[right] - p_sum[left] == N)
		{
			ans++;
			right++;
		}
	}
	
	cout << ans;	 
	
}