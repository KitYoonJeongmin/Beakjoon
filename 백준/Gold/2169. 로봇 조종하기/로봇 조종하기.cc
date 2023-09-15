#include <iostream>
#include <algorithm>
#define MAXN 1010
using namespace std;
int n, m;

int arr[MAXN][MAXN];
int dp[MAXN][MAXN];
int temp[MAXN][2];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	//첫번째 줄
	dp[0][0] = arr[0][0]; // 첫칸
	for (int j = 1; j < m; ++j) dp[0][j] = dp[0][j - 1] + arr[0][j]; //오른쪽 ------->

	for (int i = 1; i < n; ++i) {
		temp[0][0] = dp[i - 1][0] + arr[i][0]; // 아래칸(1~n-1) 좌
		temp[m - 1][1] = dp[i - 1][m - 1] + arr[i][m - 1];  //아래칸(1~n - 1) 우

		// 오른쪽 ------->
		for (int j = 1; j < m; ++j) temp[j][0] = max(dp[i - 1][j], temp[j - 1][0]) + arr[i][j];
		// <------- 왼쪽
		for (int j = m - 2; j >= 0; --j) temp[j][1] = max(dp[i - 1][j], temp[j + 1][1]) + arr[i][j];

		//오 왼중 큰값 저장
		for (int j = 0; j < m; ++j) dp[i][j] = max(temp[j][0], temp[j][1]);
	}

	cout << dp[n - 1][m - 1];

	return 0;
}