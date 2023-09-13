#include<iostream>
#include<vector>
#include <cstring>
using namespace std;
struct info
{
	info(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int x, y;
};
int N, M, map[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool visited[101][101];
vector<info> v;

void dfs(info cur)
{
	//if (visited[cur.x][cur.y]) return;
	map[cur.x][cur.y] = 2;
	//visited[cur.x][cur.x] = true;

	for (int i = 0; i < 4; i++)
	{
		int cx = cur.x + dx[i];
		int cy = cur.y + dy[i];
		if (0 > cx || cx >= N || cy < 0 || cy >= M || map[cx][cy] != 0) continue;
		dfs(info(cur.x + dx[i], cur.y + dy[i]));
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	int cheeseNum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j])
			{
				v.push_back(info(i, j));
				cheeseNum++;
			}
			
		}
	}
	//2변 이상이 외부와 접촉한다면 녹음
	//치즈의 사방면을 탐색했을 때 2면 이상 외부와 접촉했다면 녹임
	memset(visited, false, sizeof(visited));
	dfs(info(0, 0));

	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j]<<" ";
		}
		cout << '\n';
	}
	*/
	int result = 0;
	while (cheeseNum > 0)
	{
		result++;
		vector<info> v2;
		for (auto d : v)
		{
			if (map[d.x][d.y] != 1) continue;
			int cnt = 0;
			for (int i = 0; i < 4; i++)
			{
				int cx = d.x + dx[i];
				int cy = d.y + dy[i];
				if (0 > cx || cx >= N || cy < 0 || cy >= M || map[cx][cy] != 2) continue;
				cnt++;
				if (cnt >= 2)
				{
					v2.push_back(info(d.x, d.y));
					break;
				}
			}
		}
		cheeseNum -= v2.size();
		for (auto d : v2)
		{
			memset(visited, false, sizeof(visited));
			dfs(info(d.x, d.y));
		}


		//cout << cheeseNum <<'\n';
	}

	cout << result;

	return 0;
}