#include<iostream>
#include<algorithm>
using namespace std;
int dp[31][2][1001];
int main()
{
	int T; cin >> T;
	int W; cin >> W;

	int arr[1001];
	for (int i = 1; i <= T; i++)
	{
		cin >> arr[i];
	}

	for (int j = 0; j <= W; j++) {
		for (int i = 0; i < 2; i++) {
			for (int k = 1; k <= T; k++) {
				dp[j][i][k] = -1;
			}
		}
	}

	
	for (int i = 0; i <= W; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			if(i==0)
				dp[i][0][j] = dp[i][0][j - 1] + (arr[j] == 1);
			else
			{
				// j초 기준으로 위치가 1번 나무일 때
				dp[i][0][j] = max(dp[i][0][j - 1] + (arr[j] == 1), dp[i - 1][1][j - 1] + (arr[j] == 1));

				// j초 기준으로 위치가 2번 나무일 때
				dp[i][1][j] = max(dp[i][1][j - 1] + (arr[j] == 2), dp[i - 1][0][j - 1] + (arr[j] == 2));
			}
		}
	}
	int result = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= W; j++) {
			result = max(result, dp[j][i][T]);
		}
	}
	cout << result;
	return 0;
}