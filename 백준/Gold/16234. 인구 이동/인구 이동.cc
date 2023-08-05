#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int nations[51][51];
bool visited[51][51];
int N, L, R, total;
vector<pair<int, int>> v;
void dfs(int x, int y)
{
	v.push_back(make_pair(x, y));
	visited[x][y] = true;
	total += nations[x][y];

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		//범위 검사
		if (nx < 0 || nx >= N || ny < 0 || ny >= N|| visited[nx][ny]) continue;
		
		//탐색 조건 검사
		int temp = abs(nations[nx][ny] - nations[x][y]);
		if (temp < L || temp > R) continue;

		dfs(nx, ny);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> nations[i][j];
		}
	}

	int ans = 0;
	bool flag;
	while (true)
	{
		memset(visited, false, sizeof(visited));
		flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j]) continue;

				v.clear(); total = 0;
				dfs(i, j);

				if (v.size() == 1) continue;

				flag = true; //한번이라도 이동이 있음
				int n = total / v.size();
				for (auto nation : v)
				{
					nations[nation.first][nation.second] = n;
				}
			}
		}

		if (!flag) break;
		ans++;
	}

	cout << ans;
	return 0;
}