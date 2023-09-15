#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int N, M, result = 0; //y x
bool visited[51][51];
int m[51][51], dp[51][51];

int dfs(int y, int x)
{
	if (x <= 0 || x > M || y <= 0 || y > N || m[y][x] == 0) return 0;
	if (visited[x][y])
	{
		cout << -1 << endl;
		exit(0);
	}
	if (dp[x][y] != 0) return dp[x][y];

	visited[x][y] = true;
	int cur = m[y][x];
	for (int i = 0; i < 4; i++)
	{
		int cx = x + dx[i] * cur;
		int cy = y + dy[i] * cur;

		
		dp[x][y] = max(dp[x][y], dfs(cy, cx)+1);
	}
	visited[x][y] = false;
	return dp[x][y];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string s; cin >> s;
		for (int j=0; j<s.size(); j++)
		{
			if (s[j] == 'H') m[i][j+1] = 0;
			else m[i][j+1] = (s[j] - '0');
		}
	}
	

	cout << dfs(1, 1);
	
	return 0;
}