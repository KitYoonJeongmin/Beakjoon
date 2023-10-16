#include <iostream>
#include <algorithm>
using namespace std;
int arr[50001];
int dp[4][50001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num; cin >> num;
		arr[i] = arr[i-1] + num;
	}
	int len; cin >> len;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = i * len; j <= N; j++)
		{
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - len] + (arr[j] - arr[j - len]));
		}
	}
	cout << dp[3][N];

	return 0;
}