#include <iostream>

using namespace std;

int cost[10001];
int parent[10001];
bool visited[10001];
int N, M, K;

int Find(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		if (cost[a] >= cost[b]) parent[a] = b;
		else parent[b] = a;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		int c; cin >> c;
		parent[i] = i;
		cost[i] = c;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	int result = 0;

	for (int i = 1; i <= N; i++)
	{
		int cur = Find(i);
		if (!visited[cur])
		{
			result += cost[cur];
			visited[cur] = true;
		}
	}

	if (result > K) cout << "Oh no";
	else cout << result;

	return 0;
}