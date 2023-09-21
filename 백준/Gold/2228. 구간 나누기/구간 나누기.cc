#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M;
int arr[101];
int dp[101][101];

int solve(int n, int m)
{
	if(m==0) return 0;
	if(n<=0) return -32768000;
	if(dp[n][m] != -1) return dp[n][m];
	
	int sum = 0;
	dp[n][m] = solve(n-1, m);
	for(int i=n; i>0; i--)
	{
		sum += arr[i];
		int temp = solve(i-2, m-1) + sum;
		dp[n][m] = max(dp[n][m], temp);
	}
	return dp[n][m];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N >> M;
	
	for(int i=1; i<=N; i++)
	{
		cin >>arr[i];
	}
	
	memset(dp, -1, sizeof(dp));
	
	cout << solve(N, M);
	return 0;
}