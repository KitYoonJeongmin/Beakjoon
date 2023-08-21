#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> g[2001];
bool visited[2001], result;


void dfs(int cur, int depth)
{
	if (depth == 4)
	{
		result = true;
		return;
	}
	visited[cur] = true;

	for (auto next : g[cur])
	{
		if (visited[next] || result) continue;
		dfs(next, depth+1);
	}
	visited[cur] = false;

}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	result = false;
	for (int i = 0; i < N; i++)
	{
		dfs(i, 0);
		if (result)
		{
			break;
		}
		
	}
	cout << result;
	return 0;
}