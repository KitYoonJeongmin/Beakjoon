#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<cstring>
using namespace std;
bool visited[100001];
vector<pair<int, int>> v[100001];
int s, e;

bool bfs(int currentCost)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty())
	{
		int currentFactory = q.front();
		q.pop();

		if (currentFactory == e) return true; //목적지를 찾음

		for (auto nextFactory: v[currentFactory])
		{
			if (visited[nextFactory.first] == false && currentCost <= nextFactory.second)
			{
				visited[nextFactory.first] = true;
				q.push(nextFactory.first);
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M; cin >> N >> M;

	int minCost,maxCost;
	minCost = maxCost = 0;

	for (int i = 0; i < M; i++)
	{
		int p1, p2, c;
		cin >> p1 >> p2 >> c;
		v[p1].push_back(make_pair(p2, c));
		v[p2].push_back(make_pair(p1, c));

		maxCost = max(maxCost, c);
	}

	
	cin >> s >> e;



	while (minCost <= maxCost)
	{
		memset(visited, false, sizeof(visited));
		int mid = (minCost + maxCost) / 2;
		if (bfs(mid)) 
		{
			minCost = mid + 1;
		}
		else
		{
			maxCost = mid - 1;
		}
	}

	cout << maxCost;

	return 0;
}