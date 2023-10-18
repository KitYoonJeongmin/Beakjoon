#include <iostream>
#include <cstring>
using namespace std;

int N,M;
long long dp[51][700];
long long func(int index, int sum)
{
	if (index > N) return 0;
	if (sum == M) return 1;
	else if (sum > M) return 0;
	if (dp[index][sum] != -1) return dp[index][sum];

	dp[index][sum] = func(index + 1, sum + index) + func(index + 1, sum);
	return dp[index][sum];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	if ((1 + N) * N / 2 %2)
	{
		cout << 0;
		return 0;
	}
	M = (1 + N) * N / 4;
	memset(dp, -1, sizeof(dp));
	cout << func(1,0);
	return 0;
}