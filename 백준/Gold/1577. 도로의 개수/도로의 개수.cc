#include <iostream>

using namespace std;
int N, M;
long long dp[101][101];
bool road[101][101][2]; //가로, 세로
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M; //가로, 세로
	int k; cin >> k;
	for(int i=0; i<k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1==x2)
		{
			road[x1][y1>y2 ? y1: y2][0] = true;
		}
		else
		{
			road[x1>x2 ? x1: x2][y1][1] = true;
		}
	}
	dp[0][0] = 1;
	for(int i=1; i<=M; i++)
	{
		if(road[0][i][0]) continue;
		dp[0][i] = dp[0][i-1];
	}
	for(int i=1; i<=N; i++)
	{
		if(road[i][0][1]) continue;
		dp[i][0] = dp[i-1][0];
	}
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			long long a,b;
			a = b = 0;
			if(!road[i][j][0]) b = dp[i][j-1];
			if(!road[i][j][1]) a = dp[i-1][j];
			dp[i][j] = a+b;
		}
	}
	cout << dp[N][M];
	
	return 0;
}