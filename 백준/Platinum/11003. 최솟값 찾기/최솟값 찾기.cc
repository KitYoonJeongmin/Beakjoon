#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, L; cin >> N >> L;
	priority_queue<pair<int,int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
	int result;
	for (int i = 0; i < N; i++)
	{
		int n; cin >> n;
		pq.push(make_pair(n, i));
		while (pq.top().second <= i - L)
			pq.pop();
		cout << pq.top().first << ' ';
	}
	return 0;
}
