#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, result;
vector<pair<int, int>> v[10001];
bool visited[10001];

void dfs(int start, int value)
{
	visited[start] = true;
    if (value > result)
    {
        result = value;
    }
    for (auto vertex:v[start])
    {
        int y = vertex.first;

        if (!visited[y])
        {
            dfs(y, value + vertex.second);
        }
    }
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	result = 0;
	for (int i = 0; i < N-1; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		v[a].push_back(make_pair(b, d));
		v[b].push_back(make_pair(a, d));
	}
	
	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		dfs(i, 0);
	}
	cout << result;
	return 0;
}