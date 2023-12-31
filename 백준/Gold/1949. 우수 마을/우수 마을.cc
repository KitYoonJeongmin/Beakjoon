#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;
int N;
int citizens[MAX];
vector<int> links[MAX];
bool visited[MAX];
int dp[MAX][2]; // c번 노드를 루트로 하는 서브트리의 인구수 최대값 0:c가 일반도시, 1:c가 우수도시

void dfs(int c)
{
	visited[c] = true;

	dp[c][0] = 0;
	dp[c][1] = citizens[c];

	for (auto next : links[c])
	{
		if (visited[next]) continue;
		dfs(next);

		dp[c][0] += max(dp[next][0], dp[next][1]);
		dp[c][1] += dp[next][0]; // 현재 도시가 우수도시라면 인접한 도시는 일반도시
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> citizens[i];
	for (int i = 1; i < N; i++)
	{
		int s, e;
		cin >> s >> e;
		links[s].push_back(e);
		links[e].push_back(s);
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
	return 0;
}