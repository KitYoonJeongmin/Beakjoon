#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int dp[1000001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N; cin >> N;
	vector<long long> numbers;
  	for (auto i = 1; i <= N; i <<= 1) 
		numbers.push_back(i);
	
	dp[0] = 1;
	for(int i=0; i< numbers.size(); i++)
	{
		for(auto j = numbers[i]; j <= N; j++)
		{
			dp[j] += dp[j - numbers[i]];
			dp[j] %= 1000000000;
		}
	}
	
	cout << dp[N];
	return 0;
}

