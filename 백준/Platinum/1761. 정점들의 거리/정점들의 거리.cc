#include <iostream>
#include <vector>

using namespace std;

int N;
const int TREE_HIGTH = 20;
int depth[40001];
int parent[40001][TREE_HIGTH];
int dist[40001][TREE_HIGTH];
vector<pair<int, int>> adj[40001];

void FindParent(int p, int now, int d, int c) 
{
	depth[now] = d;
	parent[now][0] = p;
	dist[now][0] = c;

	for (int i = 0; i < adj[now].size(); ++i) 
	{
		if (adj[now][i].first != p) FindParent(now, adj[now][i].first, d + 1, adj[now][i].second);
	}
}

int DistNodePair(int a, int b) 
{
    int sum = 0;
    if (depth[a] != depth[b]) 
    {
        if (depth[a] < depth[b]) swap(a, b);

        int dif = depth[a] - depth[b];
        for (int i = 0; dif > 0; ++i) 
        {
            if (dif % 2 == 1) 
            {
                sum += dist[a][i];
                a = parent[a][i];
            }
            dif = dif / 2;
        }
    }

    if (a != b) {
        for (int k = TREE_HIGTH - 1; k >= 0; --k) {
            if (parent[a][k] != 0 && parent[a][k] != parent[b][k]) {
                sum += (dist[a][k] + dist[b][k]);
                a = parent[a][k];
                b = parent[b][k];
            }
        }

        sum += dist[a][0] + dist[b][0];
    }

    return sum;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	int a, b, c;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

    FindParent(0, 1, 0, 0);

    for (int k = 1; k < TREE_HIGTH; ++k) 
    {
        for (int i = 2; i <= N; i++) 
        {
            if (parent[i][k - 1] != 0) 
            {
                parent[i][k] = parent[parent[i][k - 1]][k - 1];
                dist[i][k] = dist[i][k - 1] + dist[parent[i][k - 1]][k - 1];
            }
        }
    }

    int M; cin >> M;

    while (M--)
    {
        cin >> a >> b;
        cout << DistNodePair(a, b) << '\n';
    }

	return 0;
}