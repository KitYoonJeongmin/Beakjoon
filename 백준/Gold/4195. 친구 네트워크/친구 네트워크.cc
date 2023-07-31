#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
int parents[200001],friendNum[200001];

int Find(int a)
{
	if (parents[a] == a) return a;
	return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a < b)
	{
		parents[b] = a;
		friendNum[a] += friendNum[b];
	}
	else if(a>b)
	{
		parents[a] = b;
		friendNum[b] += friendNum[a];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC; cin >> TC;


	while (TC--)
	{
		int f; cin >> f;
		
		for (int i = 0; i <= 200000; i++)
		{
			parents[i] = i;
			friendNum[i] = 1;
		}
		map<string, int> map;
		int count = 0;

		for (int i = 0; i < f; i++)
		{
			string a, b;
			cin >> a >> b;
			if (map.find(a) == map.end()) map[a] = ++count;
			if (map.find(b) == map.end()) map[b] = ++count;

			Union(map[a], map[b]);

			int p1 = Find(map[a]);
			int p2 = Find(map[b]);

			cout << max(friendNum[p1], friendNum[p2]) << '\n';
		}

	}

	return 0;
}

