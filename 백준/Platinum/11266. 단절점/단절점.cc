#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N, E;
vector<int> v[10001], ans;
int visited[10001];
bool cut[10001];
int cnt;

int dfs(int currentNode, bool isRoot)
{
	visited[currentNode] = cnt++;
	int ret = visited[currentNode];
	int child = 0;

	for (int i = 0; i < v[currentNode].size(); i++)
	{
		int next = v[currentNode][i];
		if (visited[next] == -1) //아직 탐색하지 않았다면
		{
			child++;
			int subtree = dfs(next, false);

			if (!isRoot && subtree >= visited[currentNode]) cut[currentNode] = true; // 루트가 아니고 하위 노드들이 현재 노드 이후에 탐색된다면 현재 정점은 단절점
			ret = min(ret, subtree);
		}
		else
		{
			ret = min(ret, visited[next]);
		}
	}
	if (isRoot && child >= 2) cut[currentNode] = true;
	return ret;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	memset(visited, -1, sizeof(visited));
	cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == -1) dfs(i, true);
	}
	for (int i = 1; i <= N; i++)
	{
		if (cut[i]) ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}