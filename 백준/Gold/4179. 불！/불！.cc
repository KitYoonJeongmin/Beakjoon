#include <iostream>
#include <string>
#include <queue>
using namespace std;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int R, C;
int map[1001][1001];
queue<pair<int, int>> fire, q;
int main()
{
	ios::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < C; j++)
		{
			switch (s[j])
			{
			case '.':
				map[i][j] = 1;
				break;
			case 'F':
				map[i][j] = 2;
				fire.push({ i,j });
				break;
			case '#':
				map[i][j] = 3;
				break;
			case 'J':
				map[i][j] = 1;
				q.push({ i,j });
				break;
			}
		}
	}
	
	
	
	long long answer = 0;
	bool visited[1001][1001] = { false };
	while (!q.empty())
	{
		int fire_size = fire.size();
		for (int n = 0; n < fire_size; n++)
		{
			int f_x = fire.front().first;
			int f_y = fire.front().second;
			fire.pop();
			
			for (int i = 0; i < 4; i++)
			{
				int nx = f_x + dx[i];
				int ny = f_y + dy[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (map[nx][ny] > 1) continue;
				
				map[nx][ny] = 2;
				fire.push({ nx, ny });
			}
		}
		
		int q_size = q.size();
		for (int n = 0; n < q_size; n++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == 0 || x == R - 1 || y == 0 || y == C - 1)
			{
				cout << answer + 1;
				return 0;
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				

				if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny]) continue;
				if (map[nx][ny] > 1) continue;
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
		answer++;
	}
	cout << "IMPOSSIBLE";

	return 0;
}