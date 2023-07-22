#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	stack<pair<int, int>> s;
	int N; cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int H; cin >> H;

		while (!s.empty())
		{
			if (H < s.top().second)
			{
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		if (s.empty())
		{
			cout << 0 << " ";
		}
		s.push(make_pair(i, H));
	}

	return 0;
}