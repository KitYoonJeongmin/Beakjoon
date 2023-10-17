#include <iostream>

using namespace std;
int N;
int map[33][33];
long long dp[33][33][3];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}
	dp[1][2][0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] != 0) continue;
			//dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][j][0] += (dp[i][j - 1][0] + dp[i][j - 1][2]);
			dp[i][j][1] += (dp[i - 1][j][1] + dp[i - 1][j][2]);
			if (map[i][j - 1] == 0 && map[i - 1][j] == 0) 
				dp[i][j][2] += (dp[i - 1][j - 1][0]+ dp[i - 1][j - 1][1]+ dp[i - 1][j - 1][2]);
		}
	}
	
	long long result = 0;
	for (int i = 0; i < 3; i++)
	{
		result += dp[N][N][i];
	}
	
	cout << result;
	return 0;
}