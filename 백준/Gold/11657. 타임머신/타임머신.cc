#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define INF 2e9

int N, M;

int a, b;
long long dist[501];
bool cycle;
vector<pair<int, int>> v[501];

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
        int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	
	for (int i = 1; i <= N; i++)
		dist[i] = INF; // 모든 노드를 INF로 세팅

	dist[1] = 0; // 시작점 0으로 초기화
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < v[j].size(); k++)
			{
				int next = v[j][k].first;
				int d = v[j][k].second;

				if (dist[j] != INF && dist[next] > dist[j] + d)
				{
					dist[next] = dist[j] + d;
					if (i == N) cycle = true;
				}
					
			}
		}

	if (cycle) cout << -1;
	else
	{
		for (int i = 2; i <= N; i++)
			cout << (dist[i] != INF ? dist[i] : -1) << '\n';
	}

	return 0;
}