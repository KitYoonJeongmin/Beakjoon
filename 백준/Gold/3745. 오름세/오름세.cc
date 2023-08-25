#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie();

	int N;
	while (cin >> N)
	{
		vector<int> v;
		for (int i = 0; i < N; i++)
		{
			int n; cin >> n;
			if (v.empty() || v.back() < n) v.push_back(n);
			else
			{
				int index = lower_bound(v.begin(), v.end(), n) - v.begin();
				v[index] = n;
			}
		}
		cout << v.size()<<'\n';
	}
	
	return 0;
}