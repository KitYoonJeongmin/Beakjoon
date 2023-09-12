#include <iostream>
#include <queue>
using namespace std;
int K, W, H;
short dx[] = { 0,1,0,-1,2,2,-2,-2,1,-1,1,-1 };
short dy[] = { 1,0,-1,0,1,-1,1,-1,2,2,-2,-2 };
bool m[201][201];
int visited[201][201][31];

struct node
{
	node(int a, int b, int c)
	{
		x = a;
		y = b;
		k = c;
	}
	int x, y, k;
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> K;
	cin >> W >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> m[i][j];
		}
	}

	queue<node> q;
	q.push(node(0, 0, K));
	visited[0][0][K] = 0;
	int bound;
	while (!q.empty())
	{
		node cur = q.front();
		q.pop();
		
		if (cur.x == H - 1 && cur.y == W - 1)
		{
			cout << visited[cur.x][cur.y][cur.k];
			return 0;
		}
		bound = 4;
		if (cur.k > 0) bound = 12;
		int nk;
		for (int i = 0; i < bound; i++)
		{
			nk = cur.k;
			if (i >= 4) nk -= 1;
			if (cur.x + dx[i] < 0 || cur.x + dx[i] >= H || cur.y + dy[i] < 0 || cur.y + dy[i] >= W || m[cur.x + dx[i]][cur.y + dy[i]] || visited[cur.x + dx[i]][cur.y + dy[i]][nk]) continue;
			visited[cur.x + dx[i]][cur.y + dy[i]][nk] = visited[cur.x][cur.y][cur.k] + 1;
			q.push(node(cur.x + dx[i], cur.y + dy[i], nk));
		}
		
	}


	cout << -1;

}