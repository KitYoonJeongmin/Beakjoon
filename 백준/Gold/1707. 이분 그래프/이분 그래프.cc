#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int V, E;
vector<int> vec[20001];
int visited[20001];
void dfs(int s)
{
	if (visited[s] == 0) visited[s] = 2;

	for (auto index : vec[s])
	{
		if (visited[index] == 0)
		{
			if (visited[s] == 2)
				visited[index] = 3;
			else if (visited[s] == 3)
				visited[index] = 2;

			dfs(index);
		}
	}
}

bool check()
{
	for (int i = 1; i <= V; i++)
	{
		for (auto index:vec[i])
		{
			if (visited[i] == visited[index])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	while (T--)
	{
		cin >> V >> E;
        //입력
		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
        //탐색
		for (int i = 1; i <= V; i++)
		{
			if (visited[i] == 0) dfs(i);
		}
        
        //체크
		if (check() == 0) 
			cout << "NO\n";
		else
			cout << "YES\n";
        
        //초기화
		memset(visited, 0, sizeof(visited));
		memset(vec, 0, sizeof(vec));
	}
	
	return 0;
}