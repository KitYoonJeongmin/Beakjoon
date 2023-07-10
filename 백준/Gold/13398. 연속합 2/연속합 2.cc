#include <iostream>

using namespace std;



int main()
{

	int N; cin >> N;
	int nums[100001];
	int dp[100001][2];
	
	
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		
	}
	int result = nums[0];
	dp[0][0] = nums[0];
	dp[0][1] = nums[0];
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = max(dp[i - 1][0] + nums[i], nums[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
		result = max(result, max(dp[i][0], dp[i][1]));

	}
	
	cout << result;



	return 0;
}