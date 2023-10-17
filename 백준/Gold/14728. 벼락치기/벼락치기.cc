#include <iostream>

using namespace std;
int times[101];
int scores[101];
int dp[10001];
int main()
{
	ios::sync_with_stdio(false);
	int N, T; cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		cin >> times[i] >> scores[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int t = T; t>= times[i]; t--)
		{
			dp[t] = max(dp[t], dp[t- times[i]]+ scores[i]);
		}
	}
	cout << dp[T];
	return 0;
}