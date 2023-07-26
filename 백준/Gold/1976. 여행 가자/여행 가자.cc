#include <iostream>
using namespace std;

int parents[201];

int Find(int n)
{
	if (n == parents[n]) return n;
	return parents[n]=Find(parents[n]);
}

void Union(int n1, int n2)
{
	n1 = Find(n1);
	n2 = Find(n2);
	if (n1 < n2) parents[n2] = n1;
	else parents[n1] = n2;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		parents[i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int con; cin >> con;
			if (con == 0) continue;

			Union(i, j);
		}
	}

	int s;
	for (int i = 0; i < M; i++)
	{
		int n; cin >> n;

		if (i == 0) s = Find(n);
		else
		{
			if(Find(s)!= Find(n))
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}