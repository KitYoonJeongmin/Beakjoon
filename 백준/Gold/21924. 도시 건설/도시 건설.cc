#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[100001];
int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	parent[y] = x;
}
bool checkParent(int x, int y)
{
	x = find(x);
	y = find(y);
	return x == y;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	int v, e; cin >> v >> e;
	vector<pair<int, pair<int, int>>> vec;

	long long result = 0, all = 0;
	for (int i = 0; i < e; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		vec.push_back({ c,{s,e} });
		all += c;
	}
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= v; i++) parent[i] = i;
	for (int i = 0; i < vec.size(); i++)
	{
		if (!checkParent(vec[i].second.first, vec[i].second.second))
		{
			uni(vec[i].second.first, vec[i].second.second);
			result += vec[i].first;
		}
	}

	for (int i = 2; i <= v; i++)
	{
		if (!checkParent(parent[1], parent[i]))
		{
			cout << -1;
			return 0;
		}
	}

	cout << all - result;

	return 0;
}