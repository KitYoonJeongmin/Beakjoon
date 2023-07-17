#include <iostream>

using namespace std;
int parent[1000000];

int find(int u) 
{
	if (parent[u] == u) return u; //본인이랑 같으면 종료
	return parent[u] = find(parent[u]); //재귀적으로 찾음
}

void union_node(int u, int v)
{
	u = find(u); //부모 찾아서
	v = find(v);

	if (u == v) return; //같으면 그대로 종료
	else  //다르면 합쳐준 뒤 종료
	{
		parent[u] = v;
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++)
		parent[i] = i;

	while (M--)
	{
		int c, a, b;
		cin >> c >> a >> b;

		if (c == 0)
		{
			union_node(a, b);
		}
		else
		{
			a = find(a);
			b = find(b);
			if (a == b) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}

	return 0;
}