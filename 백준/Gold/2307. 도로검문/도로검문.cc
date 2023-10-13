#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 2e9
using namespace std;
typedef pair<int, int> pii;
int N, M;

vector<pii> edges[1001], opt;
int dist[1001];
void djikstra(int s, int e)
{
	for (int i = 1; i <= N; i++) dist[i] = MAX;
	priority_queue<pii> pq;
	dist[1] = 0;
	pq.push({ 0,1 }); // cost, startVertex

	while (!pq.empty())
	{
		int cost = -1 * pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (pii nextVertex : edges[cur])
		{
			if (cur == s && nextVertex.first == e) continue;
			if (cur == e && nextVertex.first == s) continue;
			int nCost = cost + nextVertex.second;
			if (nCost < dist[nextVertex.first])
			{
				dist[nextVertex.first] = nCost;
				pq.push({ -1 * nCost, nextVertex.first });
				if(s==0 && e == 0) opt.push_back({ cur, nextVertex.first });
			}
		}
	}
	//cout << dist[N] << '\n';
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		edges[a].push_back({ b, t });
		edges[b].push_back({ a, t });
	}
	djikstra(0,0);
	int minimumDistance = dist[N];
	int answer = 0;

	if (dist[N] == MAX)
	{
		cout << 0 << '\n';
		return 0;
	}

	for (auto edge : opt)
	{
		djikstra( edge.first, edge.second);
		if (dist[N] == MAX)
		{
			cout << -1 << '\n';
			return 0;
		}

		answer = max(answer, dist[N] - minimumDistance);
	}
	cout << answer<<'\n';
	return 0;
}