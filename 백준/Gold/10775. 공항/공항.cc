#include <iostream>

using namespace std;

int parents[100001];

int Find(int n)
{
	if (parents[n] == n) return n;
	return parents[n] = Find(parents[n]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	parents[b] = a;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int G, P; cin >> G >> P;

	for (int i = 0; i <= G; i++)
	{
		parents[i] = i;
	}

	int result = 0;
	for (int i = 0; i < P; i++)
	{
		int gi; cin >> gi;
		int parent = Find(gi);
		if (parent == 0) break;

		++result;
		Union(parent - 1, parent);
	}

	cout << result;
	

	return 0;
}