#include<iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, D, map[16][16], result;
int dx[3] = { -1,0,1 };
int dy[3] = { 0,-1,0 };
queue<pair<int, int>> q;

void func(int x, int y, int z)
{
	int map2[16][16];
	bool check[16][16], visit[16][16];
	int archer[3] = { x,y,z }; // 현재 궁수 위치 (x축 좌표)
	int pos = N + 1; // 현재 궁수 위치 (y축 좌표)
	int kill = 0;


	// 맵 복사 및 체크 표시 초기화
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			map2[i][j] = map[i][j];
			check[i][j] = false;
		}
	}
		


	while (pos > 1)
	{
		for (int i = 0; i < 3; i++) // 궁수 3명
		{
			// 방문 여부 초기화
			for (int j = 1; j <= N; j++)
				for (int k = 1; k <= M; k++)
					visit[j][k] = false;

			q = queue<pair<int, int>>(); // 큐 초기화
			int init_x = archer[i];
			int init_y = pos - 1;

			q.push({ init_x, init_y });

			// 적 탐색
			while (!q.empty())
			{
				int now_x = q.front().first;
				int now_y = q.front().second;
				q.pop();

				visit[now_y][now_x] = true; // 방문 표시

				if (map2[now_y][now_x] == 1) // 적 발견시
				{
					check[now_y][now_x] = true; // 공격 표시
					break;
				}

				for (int j = 0; j < 3; j++) // 좌,상,우 순으로 탐색
				{
					int next_x = now_x + dx[j];
					int next_y = now_y + dy[j];
					if (next_x >= 1 && next_x <= M && next_y >= 1 && next_y <= N) // 갈려는 곳이 맵 범위에서 벗어나지 않고 
						if ((abs(archer[i] - next_x) + abs(pos - next_y) <= D)) // 궁수 사정거리 내에 있으며
							if (!visit[next_y][next_x]) // 방문한 적이 없을 때
								q.push({ next_x, next_y });

				}
			}

		}

		// 공격 표시된 적들 제거
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (check[i][j])
					map2[i][j] = 0;


		pos--; // 궁수들 한칸 위로 이동
	}

	// 공격당한 적들 카운트
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (check[i][j]) kill++;

	result = max(result, kill);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M >> D;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = j + 1; k <= M; k++)
			{
				func(i, j, k);
			}
		}
	}

	cout << result;
	return 0;
}