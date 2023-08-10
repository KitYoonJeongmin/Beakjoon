#include<iostream>
#include <cstring>
#include <vector>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int map[302][302];
int N, M;

bool visited[302][302];
struct node
{
	int x, y, change;
};
vector<node> v;
void dfs(int x, int y)
{
	visited[x][y] = true;
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < M && ny >= 0 && ny < N) //bound searching
		{
			if (map[nx][ny] > 0)
			{
				if (!visited[nx][ny])dfs(nx, ny);
			}
			else ++cnt;
				
		}
	}
	node n;
	n.x = x; n.y = y; n.change = map[x][y] - cnt;
	v.push_back(n);
}
int main()
{
	
	ios::sync_with_stdio(false); cin.tie();
	cin >> N >> M;


	for (int j = 0; j < N; j++)
		for (int i = 0; i < M; i++)
			cin >> map[i][j];

	int count = 0;
	int cnt = 0;
	while (true)
	{
		v.clear();
		cnt = 0;
		memset(visited, false, sizeof(visited));


		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j] && map[i][j] > 0)
				{
					dfs(i, j);
					++cnt;
				}
			}
		if (cnt == 0)
		{
			cout << 0; return 0;
		}
		else if (cnt >= 2)
		{
			cout << count; return 0;
		}
		count++;

		for (auto n : v)
		{
			map[n.x][n.y] = n.change;
		}
	}

	return 0;
}
