#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N, arr[1001], dp[1001][1001];
int dfs(int l, int r, int turn)
{
	if (l > r) return 0;
	if (dp[l][r]>0) return dp[l][r];

	if (turn % 2) // kun
		dp[l][r] = max(arr[l] + dfs(l + 1, r, turn + 1), arr[r] + dfs(l, r - 1, turn + 1));
	else //myng
		dp[l][r] = min(dfs(l + 1, r, turn + 1), dfs(l, r - 1, turn + 1));
	return dp[l][r];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while (T--)
	{
		cin >> N;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= N; i++) cin >> arr[i];
		cout << dfs(1, N, 1) << '\n';
	}

	return 0;
}