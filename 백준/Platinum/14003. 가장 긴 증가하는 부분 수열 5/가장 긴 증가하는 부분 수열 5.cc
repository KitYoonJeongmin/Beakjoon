#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int arr[1000001];
int main()
{
	ios::sync_with_stdio(false); cin.tie();

	int N, k = 0; cin >> N;
	vector<int> v, dp;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < N; ++i)
	{
		if (v.empty() || v.back() < arr[i])
		{
			v.push_back(arr[i]);
			dp.push_back(k); k++;
		}
		else
		{
			int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[index] = arr[i];
			dp.push_back(index);
		}
	}
	cout << v.size() << '\n';

	stack<int> s;

	for (int i = N - 1; i >= 0; i--)
	{
		if (dp[i] == k-1)
		{
			s.push(arr[i]);
			--k;
		}
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	
	return 0;
}