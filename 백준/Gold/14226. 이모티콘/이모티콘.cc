#include <iostream>
#include <queue>
using namespace std;

int s;
int visited[3001][3001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> s;

	queue<pair<int, int>> q;
	q.push({ 1,0 });
	visited[1][0] = 1;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int now = cur.first;
		int clip = cur.second;

		if (now == s)
		{
			cout << visited[now][clip] - 1 << '\n';
			break;
		}

		//복사
		int nextClip = now;
		if (visited[now][nextClip] == 0)
		{
			q.push({ now, nextClip });
			visited[now][nextClip] = visited[now][clip] + 1;
		}

		//붙여넣기
		int pasted = now + clip;
		if (pasted <= s && visited[pasted][clip] == 0)
		{
			q.push({ pasted, clip });
			visited[pasted][clip] = visited[now][clip] + 1;
		}

		//삭제
		if (now == 0) continue;
		if (visited[now - 1][clip] == 0)
		{
			q.push({ now - 1, clip });
			visited[now - 1][clip] = visited[now][clip] + 1;
		}
	}


	return 0;
}