#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
vector<ll> v;

int weight[31];
ll result;
void dfs(int s, int e, vector<ll> & p, ll sum)
{
	if (s > e)
	{
		p.push_back(sum);
		return;
	}
	else
	{
		dfs(s + 1, e, p, sum);
		dfs(s + 1, e, p, sum + v[s]);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, C; cin >> N >> C;
	v.resize(N, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	vector<ll> p1, p2;
	dfs(0, N / 2 - 1, p1, 0); // 앞 부분에서 나올 수 있는 합을 p1에 저장
	dfs(N / 2, N - 1, p2, 0); // 뒷 부분에서 나올 수 있는 합을 p2에 저장
	sort(p2.begin(), p2.end()); // p2는 정렬(이분탐색을 위해)
	int result = 0;
	for (int i = 0; i < p1.size(); i++)
	{
		ll x = C - p1[i];
		result += upper_bound(p2.begin(), p2.end(), x) - p2.begin();
	}
	
	cout << result;
	return 0;
}