#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int cost[1001];

bool compare(pair<int, int>& v1, pair<int, int>& v2) {

	if (v1.second == v2.first) {
		return v1.first < v1.first;
	}
	else return v1.second > v2.second;
}

int main()
{
	ios::sync_with_stdio(false);

	int N; cin >> N;

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), compare);

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = v[i].first; j > 0; j--)
		{
			if (cost[j]==0)
			{
				cost[j] = v[i].second;
				answer += v[i].second;
				break;
			}
		}
	}
	cout << answer;

	return 0;
}
