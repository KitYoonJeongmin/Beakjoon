#include<iostream>
#include <queue>
using namespace std;
short map[101][101];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int N;
void LandBFS(int x, int y, int n)
{
	bool visited[101][101] = { false };
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		map[cx][cy] = n;
		
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || map[nx][ny] == 0 || visited[nx][ny]) continue;
			q.push({ nx,ny });
			visited[nx][ny] = true;
		}
	}
}

int bfs(int x, int y)
{
	int landNum = map[x][y];
	bool visited[101][101] = { false };
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{ x,y } });
	visited[x][y] = true;
	while (!q.empty())
	{
		int count = q.front().first;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || map[nx][ny] == landNum ||visited[nx][ny]) continue;
			if (map[nx][ny] == 0)
			{
				visited[nx][ny] = true;
				q.push({ count + 1, { nx,ny } });
			}
			else if (map[nx][ny] != landNum) return count;
		}
	}
	return 2e9;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	
	int land = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)
			{
				LandBFS(i, j, land);
				land--;
			}
		}
	}

	int result = 2e9;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0) continue;
			result = min(result, bfs(i, j));
		}
	}
	cout << result << '\n';
	return 0;
}