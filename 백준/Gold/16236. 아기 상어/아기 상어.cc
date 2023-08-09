#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct Node
{
	int x, y;
};
struct Fish
{
	int time;
	Node location;
};
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
Node babysharkLoc;
bool visited[21][21], canEat;
int map[21][21], sharkSize, result,N;


void bfs()
{
	queue<Fish> q;
	Fish currentFish; currentFish.time = 0; currentFish.location.x = babysharkLoc.x; currentFish.location.y = babysharkLoc.y;
	q.push(currentFish);
	visited[babysharkLoc.x][babysharkLoc.y] = true;
	int temp=0;
	while (!q.empty())
	{
		int cx = q.front().location.x;
		int cy = q.front().location.y;
		int t = q.front().time;
		q.pop();
		
		if (map[cx][cy] > 0 && map[cx][cy] < sharkSize && temp == t)
		{
			if (babysharkLoc.x > cx || (babysharkLoc.x == cx && babysharkLoc.y > cy))
			{
				babysharkLoc.x = cx;
				babysharkLoc.y = cy;
				continue;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny])
			{
				if (map[nx][ny]>0 && map[nx][ny] < sharkSize && !canEat)
				{
					canEat = true;
					babysharkLoc.x = nx;
					babysharkLoc.y = ny;
					temp = t + 1;
					result += temp;
				}
				else if(map[nx][ny] <= sharkSize)
				{
					Fish nextFish; nextFish.location.x = nx; nextFish.location.y = ny; nextFish.time = t+1;
					q.push(nextFish);
					visited[nx][ny] = true;
				}
			}
		}
	}
	
	
	
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(); cout.tie();
	
	cin >> N;
	
	int count = 0;
	result = 0;
	sharkSize = 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				babysharkLoc.x = i;
				babysharkLoc.y = j;
				map[i][j] = 0;
			}
		}
	}

	while (true)
	{
		memset(visited, 0, sizeof(visited));
		bfs();
		if (canEat)
		{
			canEat = false;
			count++;
			map[babysharkLoc.x][babysharkLoc.y] = 0;
			if (count == sharkSize) //자기 사이즈 만큼 먹으면 증가
			{
				sharkSize++;
				count = 0;
			}
			
		}
		else
		{
			break;
		}
	}

	cout << result;



	return 0;
}

