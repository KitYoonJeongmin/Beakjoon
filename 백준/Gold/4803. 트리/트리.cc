#include<iostream>
#include <vector>
using namespace std;

bool visited[501];
vector<int> graph[501];

bool dfs(int currentX, int postX)
{
	visited[currentX] = true;

	for (int i = 0; i < graph[currentX].size(); i++)
	{
		int nextX = graph[currentX][i];
		if (nextX == postX) continue; //이전꺼랑 같아서 사이클 발생

		if (visited[nextX]) return false; //사이클 발생
		if (!dfs(nextX, currentX)) return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int count = 0;

	while (true)
	{
		count++;
		
		int N, M; cin >> N >> M; //정점의 개수, 간선의 개수
		if (N == 0 && M == 0) break;

		for (int i = 0; i <= 500; i++)
		{
			graph[i].clear();
			visited[i] = false;
		}

		for (int i = 0; i < M; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int result = 0;
		cout << "Case " << count << ": ";

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
			{
				if (dfs(i, 0)) ++result;
			}
		}

		if (result == 0) cout << "No trees." << '\n';
		else if (result == 1) cout << "There is one tree." << '\n';
		else cout << "A forest of " << result << " trees." << '\n';
	}


	return 0;
}


